#ifndef VIENNACL_GENERATOR_CODE_GENERATION_TEMPLATES_GEMV_HPP
#define VIENNACL_GENERATOR_CODE_GENERATION_TEMPLATES_GEMV_HPP

#include "viennacl/generator/code_generation/optimization_profile.hpp"
#include "viennacl/generator/symbolic_types_base.hpp"

namespace viennacl{

namespace generator{

namespace code_generation{

namespace gemv{

class profile : public optimization_profile{
public:

    profile(){
        m_ = 32;
        k_ = 32;
        num_groups_0_ = 1024;
    }

    std::pair<size_t,size_t> local_work_size() const{
        return std::make_pair(m_,k_);
    }

    void config_nd_range(viennacl::ocl::kernel & k, infos_base* p){
        k.local_work_size(0,m_);
        k.local_work_size(1,k_);
        k.global_work_size(0,m_*num_groups_0_);
        k.global_work_size(1,k_);
    }

    unsigned int m() const { return m_; }
    unsigned int k() const { return k_; }
    unsigned int num_groups_0() const { return num_groups_0_; }

    std::string repr() const{
        std::ostringstream oss;
        oss << "V" << vectorization_;
        oss << "M" << m_;
        oss << "K" << k_;
        oss << "NG0" << num_groups_0_;
        return oss.str();
    }

private:
    unsigned int m_;
    unsigned int k_;
    unsigned int num_groups_0_;
};


class generator : public code_generation::generator{
public:
    generator(std::list<infos_base * > const & expressions
              , profile * prof): expressions_(expressions), profile_(prof)
    {
        for(std::list<infos_base*>::const_iterator it=expressions_.begin() ; it!=expressions_.end() ; ++it){
            extract_as(*it, gpu_scalars_,  utils::is_type<gpu_scal_infos_base>());
            extract_as(*it, matrices_, utils::is_type<mat_infos_base>());
            extract_as(*it, vectors_, utils::is_type<vec_infos_base>());
        }
    }

    void operator()(kernel_generation_stream& kss){
            mat_infos_base* first_matrix = *matrices_.begin();

            std::string scalartype = first_matrix->scalartype();
            std::string internal_size1 = first_matrix->internal_size1();
            std::string internal_size2 = first_matrix->internal_size2();

            unsigned int m = profile_->m();
            unsigned int k = profile_->k();

            bool is_lhs_transposed = (*matrices_.begin())->is_transposed();
            std::map<matvec_prod_infos_base*, std::pair<std::string,std::pair<local_memory<2>, vec_infos_base*> > > reductions;
            for(std::list<infos_base*>::iterator it = expressions_.begin(); it!=expressions_.end() ; ++it){
                unsigned int id = std::distance(expressions_.begin(),it);
                binary_vector_expression_infos_base * vec_expr = dynamic_cast<binary_vector_expression_infos_base*>(*it);
                vec_infos_base* assigned = dynamic_cast<vec_infos_base*>(&vec_expr->lhs());
                local_memory<2> lmem("block_"+to_string(id),m,k+1,scalartype);
                std::set<matvec_prod_infos_base *, viennacl::generator::deref_less >  prods;
                extract_as(*it, prods, utils::is_type<matvec_prod_infos_base>());
                assert(prods.size()==1 && "More than one product involved in the expression");
                reductions.insert(std::make_pair(*prods.begin(),std::make_pair("reduction_"+to_string(id),std::make_pair(lmem,assigned))));
            }
            kss << "unsigned int lid0 = get_local_id(0);" << std::endl;
            kss << "unsigned int lid1 = get_local_id(1);" << std::endl;

            for(std::map<matvec_prod_infos_base*, std::pair<std::string,std::pair<local_memory<2>, vec_infos_base*> > >::iterator it = reductions.begin() ; it != reductions.end() ; ++it){
                kss << it->second.second.first.declare() << ";" << std::endl;
            }


            if(is_lhs_transposed)
                kss << "for(unsigned int c = get_global_id(0) ; c < " << internal_size2 << " ; c += get_global_size(0)){" << std::endl;
            else
                kss << "for(unsigned int r = get_global_id(0) ; r < " << internal_size1 << " ; r += get_global_size(0)){" << std::endl;
            kss.inc_tab();

            for(std::map<matvec_prod_infos_base*, std::pair<std::string,std::pair<local_memory<2>, vec_infos_base*> > >::iterator it = reductions.begin() ; it != reductions.end() ; ++it){
                matvec_prod_infos_base* prod = it->first;
                binary_op_infos_base const & op_reduce = prod->op_reduce();
                std::string const & sum_name = it->second.first;
                local_memory<2> const & lmem = it->second.second.first;
                vec_infos_base * assigned = it->second.second.second;
                kss << scalartype << " " << sum_name << " = 0;" << std::endl;
                if(is_lhs_transposed)
                    kss << "for(unsigned int r = get_global_id(1) ; r < " << internal_size1 << " ; r += get_global_size(1)){" << std::endl;
                else
                    kss << "for(unsigned int c = get_global_id(1) ; c < " << internal_size2 << " ; c += get_global_size(1)){" << std::endl;
                kss.inc_tab();

                if(is_lhs_transposed){
                    prod->lhs().access_index(0,"c + r*" + internal_size2);
                    prod->rhs().access_index(0,"r");
                }
                else{
                    prod->lhs().access_index(0,"c + r*" + internal_size2);
                    prod->rhs().access_index(0,"c");
                }

                kss << sum_name << " = " << op_reduce.generate(sum_name,prod->generate(0)) << ";" << std::endl;

                kss.dec_tab();
                kss << "}" << std::endl;

                kss << lmem.access("lid0", "lid1")<< " = " << sum_name << ";" << std::endl;

                for(unsigned int stride = k/2 ; stride>0 ; stride /=2){
                    kss << "barrier(CLK_LOCAL_MEM_FENCE); ";
                    kss <<  "if(lid1 < " << to_string(stride) << ")" << lmem.access("lid0", "lid1") <<  " = " <<   op_reduce.generate(lmem.access("lid0", "lid1"),lmem.access("lid0", "lid1+" + to_string(stride))) << ";" << std::endl;
                }
                kss << "if(lid1==0)" << assigned->name() ;
                if(is_lhs_transposed) kss << "[c]" ;
                else kss << "[r]" ;
                kss << " = " << lmem.access("lid0","0") << ";" << std::endl;
            }


            kss.dec_tab();
            kss << "}" << std::endl;
    }



private:
    std::list<infos_base* >  expressions_;
    std::set<vec_infos_base *, viennacl::generator::deref_less >  vectors_;
    std::set<mat_infos_base *, viennacl::generator::deref_less >  matrices_;
    std::set<gpu_scal_infos_base *, viennacl::generator::deref_less > gpu_scalars_;
    profile * profile_;
};

}

}

}

}

#endif
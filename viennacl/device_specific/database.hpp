#ifndef VIENNACL_DEVICE_SPECIFIC_DATABASE_HPP_
#define VIENNACL_DEVICE_SPECIFIC_DATABASE_HPP_

#include "viennacl/ocl/device_utils.hpp"
#include "viennacl/device_specific/forwards.h"
#include "viennacl/device_specific/templates/vector_axpy_template.hpp"
#include "viennacl/device_specific/templates/matrix_axpy_template.hpp"
#include "viennacl/device_specific/templates/reduction_template.hpp"
#include "viennacl/device_specific/templates/row_wise_reduction_template.hpp"
#include "viennacl/device_specific/templates/matrix_product_template.hpp"
#include "viennacl/scheduler/forwards.h"

namespace viennacl{

  namespace device_specific{

    namespace database{


      /////////////////////
      /// Vector AXPY
      ////////////////////
      static database_type<vector_axpy_template::parameters> vector_axpy = database_type<vector_axpy_template::parameters>
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", UINT_TYPE, vector_axpy_template::parameters(1,128,128,true))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", INT_TYPE, vector_axpy_template::parameters(1,128,128,true))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", ULONG_TYPE, vector_axpy_template::parameters(1,128,128,true))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", LONG_TYPE, vector_axpy_template::parameters(1,128,128,true))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", FLOAT_TYPE, vector_axpy_template::parameters(1,128,128,true))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", DOUBLE_TYPE, vector_axpy_template::parameters(1,128,128,true));

//          (nvidia_id, CL_DEVICE_TYPE_GPU, Fermi, "", FLOAT_TYPE, vector_axpy_template::parameters(1,1024,2048,1))
//          (amd_id, CL_DEVICE_TYPE_GPU, VolcanicIslands, "", FLOAT_TYPE, vector_axpy_template::parameters(1,128,512,0));

      /////////////////////
      /// Reduction
      ////////////////////
      static database_type<reduction_template::parameters> reduction = database_type<reduction_template::parameters>
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", UINT_TYPE, reduction_template::parameters(1,128,128,true))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", INT_TYPE, reduction_template::parameters(1,128,128,true))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", ULONG_TYPE, reduction_template::parameters(1,128,128,true))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", LONG_TYPE, reduction_template::parameters(1,128,128,true))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", FLOAT_TYPE, reduction_template::parameters(1,128,128,true))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", DOUBLE_TYPE, reduction_template::parameters(1,128,128,true));


      /////////////////////
      /// Matrix AXPY
      ////////////////////
      static database_type<matrix_axpy_template::parameters> matrix_axpy = database_type<matrix_axpy_template::parameters>
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", UINT_TYPE, matrix_axpy_template::parameters(1,8,8,8,8,true))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", INT_TYPE, matrix_axpy_template::parameters(1,8,8,8,8,true))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", ULONG_TYPE, matrix_axpy_template::parameters(1,8,8,8,8,true))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", LONG_TYPE, matrix_axpy_template::parameters(1,8,8,8,8,true))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", FLOAT_TYPE, matrix_axpy_template::parameters(1,8,8,8,8,true))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", DOUBLE_TYPE, matrix_axpy_template::parameters(1,8,8,8,8,true));

      /////////////////////
      /// Row-wise Reduction
      ////////////////////
      static database_type<row_wise_reduction_template::parameters> row_wise_reduction = database_type<row_wise_reduction_template::parameters>
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", UINT_TYPE, row_wise_reduction_template::parameters(1,8,8,1))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", INT_TYPE, row_wise_reduction_template::parameters(1,8,8,1))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", ULONG_TYPE, row_wise_reduction_template::parameters(1,8,8,1))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", LONG_TYPE, row_wise_reduction_template::parameters(1,8,8,1))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", FLOAT_TYPE, row_wise_reduction_template::parameters(1,8,8,1))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", DOUBLE_TYPE, row_wise_reduction_template::parameters(1,8,8,1));

//          (nvidia_id, CL_DEVICE_TYPE_GPU, Fermi, "", FLOAT_TYPE, row_wise_reduction_template::parameters(1,1,256,2048))
//          (amd_id, CL_DEVICE_TYPE_GPU, VolcanicIslands, "", FLOAT_TYPE, row_wise_reduction_template::parameters(1,2,128,256));


     static database_type<row_wise_reduction_template::parameters> trans_row_wise_reduction = database_type<row_wise_reduction_template::parameters>
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", UINT_TYPE, row_wise_reduction_template::parameters(1,8,8,1))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", INT_TYPE, row_wise_reduction_template::parameters(1,8,8,1))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", ULONG_TYPE, row_wise_reduction_template::parameters(1,8,8,1))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", LONG_TYPE, row_wise_reduction_template::parameters(1,8,8,1))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", FLOAT_TYPE, row_wise_reduction_template::parameters(1,8,8,1))
          (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", DOUBLE_TYPE, row_wise_reduction_template::parameters(1,8,8,1));

//          (nvidia_id, CL_DEVICE_TYPE_GPU, Fermi, "", FLOAT_TYPE, row_wise_reduction_template::parameters(1,1,256,2048))
//          (amd_id, CL_DEVICE_TYPE_GPU, VolcanicIslands, "", FLOAT_TYPE, row_wise_reduction_template::parameters(1,1,64,1024));

     /////////////////////
     /// Matrix-Matrix Product
     ////////////////////
     static database_type<matrix_product_template::parameters> matrix_product_NN = database_type<matrix_product_template::parameters>
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", UINT_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", INT_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", LONG_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", ULONG_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", FLOAT_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", DOUBLE_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8));

//         (nvidia_id, CL_DEVICE_TYPE_GPU, Fermi, "", FLOAT_TYPE, matrix_product_template::parameters(1,16,16,8,4,1,8,true,true,16,8))
//         (amd_id, CL_DEVICE_TYPE_GPU, VolcanicIslands, "", FLOAT_TYPE, matrix_product_template::parameters(1,8,16,16,8,1,4,true,true,16,8));


     static database_type<matrix_product_template::parameters> matrix_product_NT = database_type<matrix_product_template::parameters>
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", UINT_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", INT_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", LONG_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", ULONG_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", FLOAT_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,true,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", DOUBLE_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8));

//         (nvidia_id, CL_DEVICE_TYPE_GPU, Fermi, "", FLOAT_TYPE, matrix_product_template::parameters(1,16,16,8,4,1,8,true,true,32,4))
//         (amd_id, CL_DEVICE_TYPE_GPU, VolcanicIslands, "", FLOAT_TYPE, matrix_product_template::parameters(4,8,8,8,4,1,8,true,true,8,8));

     static database_type<matrix_product_template::parameters> matrix_product_TN = database_type<matrix_product_template::parameters>
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", UINT_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", INT_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", LONG_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", ULONG_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", FLOAT_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", DOUBLE_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8));

//         (nvidia_id, CL_DEVICE_TYPE_GPU, Fermi, "", FLOAT_TYPE, matrix_product_template::parameters(1,16,16,8,4,1,8,true,true,16,8))
//         (amd_id, CL_DEVICE_TYPE_GPU, VolcanicIslands, "", FLOAT_TYPE, matrix_product_template::parameters(1,16,16,16,8,1,4,true,true,16,16))

     static database_type<matrix_product_template::parameters> matrix_product_TT = database_type<matrix_product_template::parameters>
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", UINT_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", INT_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", LONG_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", ULONG_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", FLOAT_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8))
         (unknown_id, CL_DEVICE_TYPE_GPU, UNKNOWN, "", DOUBLE_TYPE, matrix_product_template::parameters(1,8,8,8,4,4,4,true,false,8,8));

//         (nvidia_id, CL_DEVICE_TYPE_GPU, Fermi, "", FLOAT_TYPE, matrix_product_template::parameters(1,16,16,16,4,1,8,true,true,16,16))
//         (amd_id, CL_DEVICE_TYPE_GPU, VolcanicIslands, "", FLOAT_TYPE, matrix_product_template::parameters(1,16,16,16,4,1,8,true,true,16,16));


      /** @brief Get the profile for a device and a descriptor */
      template<class T, class ParamT>
      inline ParamT const & get(database_type<ParamT> const & database, viennacl::ocl::device const & device)
      {
        scheduler::statement_node_numeric_type numeric_type = scheduler::statement_node_numeric_type(scheduler::result_of::numeric_type_id<T>::value);

        device_type dev_type = device.type();
        vendor_id_type vendor_id = device.vendor_id();
        ocl::device_architecture_family device_architecture = device.architecture_family();
        std::string const & device_name = device.name();

        //std::cout << "Looking up vendor ID..." << std::endl;

        /*-Vendor ID-*/
        typename database_type<ParamT>::type::map_t::const_iterator vendor_it = database.map.d.find(vendor_id);
        //Vendor not recognized => global default:
        if(vendor_it==database.map.d.end())
          return database.at(ocl::unknown_id, dev_type, ocl::UNKNOWN, "", numeric_type);


        /*-Device Type-*/
        //std::cout << "Looking up device type..." << std::endl;
        typename database_type<ParamT>::device_type_t::map_t::const_iterator device_type_it = vendor_it->second.d.find(dev_type);
        //Device type not recognized for this vendor => global default
        if(device_type_it==vendor_it->second.d.end())
          return database.at(ocl::unknown_id, dev_type, ocl::UNKNOWN, "", numeric_type);

        /*-Device Architecture-*/
        //std::cout << "Looking up device architecture..." << std::endl;
        typename database_type<ParamT>::device_architecture_t::map_t::const_iterator architecture_it = device_type_it->second.d.find(device_architecture);
        if(architecture_it==device_type_it->second.d.end())
          return database.at(ocl::unknown_id, dev_type, ocl::UNKNOWN, "", numeric_type);

        /*-Device Name-*/
        //std::cout << "Looking up device name..." << std::endl;
        typename database_type<ParamT>::device_name_t::map_t::const_iterator device_name_it = architecture_it->second.d.find(device_name);
        //Name not found => Vendor default
        if(device_name_it==architecture_it->second.d.end())
          return database.at(vendor_id, dev_type, device_architecture, "", numeric_type);

        //std::cout << "Looking up expression name.." << std::endl;
        /*-Expression-*/

        typename database_type<ParamT>::expression_t::map_t::const_iterator expression_it = device_name_it->second.d.find(numeric_type);
        //Expression not found => Vendor default
        if(expression_it==device_name_it->second.d.end())
          return database.at(vendor_id, dev_type, device_architecture, "", numeric_type);

        //std::cout << "Device found in the database! Getting profile..." << std::endl;
        //Everything okay. Return specific profile//
        return database.at(vendor_id, dev_type, device_architecture, device_name, numeric_type);
      }


    }

  }

}
#endif

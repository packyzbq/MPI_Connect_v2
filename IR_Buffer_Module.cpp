//
// Created by zhaobq on 2017-4-25.
//

#include <boost/python.hpp>
#include "Include/IRecv_buffer.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(IR_Buffer_Module){
        class_<Pack>("Pack")
                .def_readonly("tag", &Pack::tag)
                .def_readonly("ibuf", &Pack::ibuf)
                .def_readonly("sbuf", &Pack::sbuf)
                .def_readonly("size", &Pack::size)
        ;

        class_<IRecv_buffer>("IRecv_buffer")
            .def("get", &IRecv_buffer::get)
            .def("put", &IRecv_buffer::put)
            .def("empty", &IRecv_buffer::empty)
        ;
}
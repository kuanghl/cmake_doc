#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>

#include "common.h"

namespace py = pybind11;

PYBIND11_MODULE(pyprint, m)
{
    /* optional module docstring */ 
    m.doc() = "pybind11 print plugin";

    /* functions */
    m.def("add_fn", &add_fn, "A function which adds two numbers");
    m.def("printf_color", &printf_color, "A function which printf text in different colors");

    // m.def("rtRuntimeGetVersion", 
    //     [](py::array_t<int> runtimeVersion){
    //         py::buffer_info info = runtimeVersion.request();
    //         return rtRuntimeGetVersion(static_cast<int *>(info.ptr));
    //     }, "rtRuntimeGetVersion"
    // );
}
# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 2.8...3.5)

# include .h
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../inc)

# build lib
add_library(pycommon STATIC ${CMAKE_CURRENT_SOURCE_DIR}/common.c)

# add .cpp and lib
pybind11_add_module(pyprint ${CMAKE_CURRENT_SOURCE_DIR}/printf_fn.cpp)

# link lib
target_link_libraries(pyprint PRIVATE pycommon)
target_link_libraries(pyprint PRIVATE pybind11::module pybind11::embed)
set_target_properties(pyprint PROPERTIES    PREFIX "${PYTHON_MODULE_PREFIX}"
                                            SUFFIX "${PYTHON_MODULE_EXTENSION}")
                                        
# specify install directories
install(TARGETS pyprint LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
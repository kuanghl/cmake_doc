# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 2.8...3.5)

# 给项目命名,解决CMP0048
if(CMAKE_VERSION VERSION_LESS 3.0)
  set(PROJECT_VERSION 0)
else()
  cmake_policy(SET CMP0048 NEW)
endif()

# PROJECT_NAME
project(cmake_doc)

# 指定安装路径
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/out CACHE INTERNAL "install directories")

# 编译构建子目录
add_subdirectory(3rd)
add_subdirectory(src)
add_subdirectory(docs)
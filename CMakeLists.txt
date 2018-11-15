cmake_minimum_required(VERSION 2.8)

#项目名
project(longan_client_rpc)

#模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(src bin)

cmake_minimum_required(VERSION 3.5)
project(lua_playground)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/include/)
include_directories(${CMAKE_SOURCE_DIR}/external_libs/luajit/include/)
link_directories(${CMAKE_SOURCE_DIR}/external_libs/)

set(SOURCE_FILES main.cpp src/lua_execution.cpp include/lua_execution.h)
add_executable(lua_playground ${SOURCE_FILES})

target_link_libraries(lua_playground ${CMAKE_SOURCE_DIR}/external_libs/luajit/libluajit.so)
#target_link_libraries(lua_playground /usr/local/lib/libluajit-5.1.so.2.0.4)
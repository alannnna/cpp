cmake_minimum_required (VERSION 3.10.2)
project (CPP)
add_executable (hello_world hello_world.cpp)
add_executable (smart_pointers smart_pointers.cpp)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(test_hello_world test_hello_world.cpp)
target_link_libraries(test_hello_world ${CONAN_LIBS})

cmake_minimum_required (VERSION 3.10.2)
project (CPP)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" ON)
add_library(project_warnings INTERFACE)

if(CMAKE_COMPILER_IS_GNUCC)
  option(ENABLE_COVERAGE "Enable coverage reporting for gcc/clang" TRUE)

  if(ENABLE_COVERAGE)
    add_compile_options(--coverage -O0)
  endif()
endif()

# List of warnings courtesy of https://github.com/lefticus/cpp_starter_project/
target_compile_options(project_warnings
                       INTERFACE
                       -Wall
                       -Wextra # reasonable and standard
                       -Wshadow # warn the user if a variable declaration shadows one from a
                                # parent context
                       -Wnon-virtual-dtor # warn the user if a class with virtual functions has a
                                          # non-virtual destructor. This helps catch hard to
                                          # track down memory errors
                       -Wold-style-cast # warn for c-style casts
                       -Wcast-align # warn for potential performance problem casts
                       -Wunused # warn on anything being unused
                       -Woverloaded-virtual # warn if you overload (not override) a virtual
                                            # function
                       -Wpedantic # warn if non-standard C++ is used
                       -Wconversion # warn on type conversions that may lose data
                       -Wsign-conversion # warn on sign conversions
                       -Wmisleading-indentation # warn if identation implies blocks where blocks
                                                # do not exist
                       -Wduplicated-cond # warn if if / else chain has duplicated conditions
                       -Wduplicated-branches # warn if if / else branches have duplicated code
                       -Wlogical-op # warn about logical operations being used where bitwise were
                                    # probably wanted
                       -Wnull-dereference # warn if a null dereference is detected
                       -Wuseless-cast # warn if you perform a cast to the same type
                       -Wdouble-promotion # warn if float is implicit promoted to double
                       -Wformat=2 # warn on security issues around functions that format output
                                  # (ie printf)
                       )

add_executable (hello_world hello_world.cpp)
target_compile_features(hello_world PRIVATE cxx_std_17)
target_link_libraries(hello_world PRIVATE project_warnings --coverage)

add_executable (smart_pointers smart_pointers.cpp)
# TODO: Clean this up
target_compile_features(smart_pointers PRIVATE cxx_std_17)
target_link_libraries(smart_pointers PRIVATE project_warnings --coverage)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# add_executable(test_hello_world test_hello_world.cpp)
# target_link_libraries(test_hello_world ${CONAN_LIBS})

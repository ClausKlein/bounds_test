# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

cmake_minimum_required(VERSION 3.28...4.4)

project(beman.bounds_test.examples LANGUAGES CXX)

if(PROJECT_IS_TOP_LEVEL)
    find_package(beman.bounds_test 0.1.0 EXACT REQUIRED)

    enable_testing()
endif()

# Use a shorter target/output name. The long dotted executable name triggers the
# Apple linker’s defective ad-hoc signature for a small program.
function(add_bounds_test_example NAME)
    set(target "beman.bounds_test.examples.${NAME}")

    add_executable(${target})
    target_sources(${target} PRIVATE ${NAME}.cpp)
    target_compile_features(${target} PRIVATE cxx_std_20)
    target_link_libraries(${target} PRIVATE beman::bounds_test)
    set_target_properties(
        ${target}
        PROPERTIES OUTPUT_NAME "bounds-test-${NAME}"
    )
    add_test(NAME ${target} COMMAND ${target})
endfunction()

add_bounds_test_example(placeholder)
add_bounds_test_example(cartesian_plane)

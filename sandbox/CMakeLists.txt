cmake_minimum_required(VERSION 3.12)

project(sandbox)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(sandbox
    ../common/
    ../
    c:/se/libraries/c++/spdlog/include/
)
add_executable(sandbox sandbox.cpp
    ../timing/cycle_timer.cpp
    ../timing/scoped_timer.cpp
    ../timing/timing_archive.cpp
)
target_link_libraries(sandbox ws2_32.lib)
target_compile_definitions(sandbox PRIVATE _DEBUG)
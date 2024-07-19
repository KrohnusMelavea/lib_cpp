cmake_minimum_required(VERSION 3.12)

project(sandbox)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(sandbox
    ../common/
    ../
    c:/se/libraries/c++/spdlog/include/
)
add_executable(sandbox sandbox.cpp
<<<<<<< HEAD
    ../net/socket.cpp
=======
    ../timing/timing_archive.cpp
    ../timing/cycle_timer.cpp
    ../timing/scoped_timer.cpp
>>>>>>> 566a871c1a4560b89fe6c64ecf3c386d67d812bf
)
target_link_libraries(sandbox ws2_32.lib)
target_compile_definitions(sandbox PRIVATE
 _DEBUG
 CREATE_GLOBAL_TIMING_ARCHIVE
 _SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS
 )
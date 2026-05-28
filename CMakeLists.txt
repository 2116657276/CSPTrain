cmake_minimum_required(VERSION 3.22)

project(CSPTrain)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE CPP_FILES "*.cpp")

foreach (CPP_FILE ${CPP_FILES})
    if (NOT CPP_FILE MATCHES "CMakeFiles" AND NOT CPP_FILE MATCHES "cmake-build")

        get_filename_component(TARGET_NAME ${CPP_FILE} NAME_WE)
        add_executable(${TARGET_NAME} ${CPP_FILE})

    endif ()
endforeach ()
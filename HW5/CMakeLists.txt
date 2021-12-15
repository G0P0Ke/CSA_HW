cmake_minimum_required(VERSION 3.20)
project(HW5)

set(CMAKE_CXX_STANDARD 17)

# Source files list
set(SOURCE_FILES
        # Headers
        Bee.h

        # Sources
        Bee.cpp
        main.cpp
        )

add_executable(HW5 ${SOURCE_FILES})

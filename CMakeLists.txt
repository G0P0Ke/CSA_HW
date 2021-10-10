cmake_minimum_required(VERSION 3.20)
project(HW1)

set(CMAKE_CXX_STANDARD 17)

# Source files list
set(SOURCE_FILES
        # Headers
        rnd.h
        ship.h
        train.h
        plane.h
        transport.h
        container.h

        # Sources
        plane.cpp
        ship.cpp
        train.cpp
        transport.cpp
        container.cpp
        main.cpp
)

add_executable(HW1 ${SOURCE_FILES})

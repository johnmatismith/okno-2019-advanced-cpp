cmake_minimum_required(VERSION 3.13)
project(okno_2019_advanced_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(app
        main.cpp
        src/db/InMemoryDatabase.cpp
        src/db/DatabaseFactory.cpp)

target_include_directories(app PRIVATE
        include)

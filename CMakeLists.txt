cmake_minimum_required(VERSION 3.13)
project(okno_2019_advanced_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(app
        src/config/Configuration.cpp
        src/db/InMemoryDatabase.cpp
        src/db/DatabaseFactory.cpp
        src/engine/ExpressionParser.cpp
        src/engine/FieldEqualExpression.cpp
        src/engine/ParseException.cpp
        src/engine/Location.cpp
        main.cpp
)

target_include_directories(app PRIVATE include)

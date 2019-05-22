cmake_minimum_required(VERSION 3.13)
project(okno_2019_advanced_cpp)

set(CMAKE_CXX_STANDARD 17)

find_package(RapidJSON)

link_libraries(stdc++fs)

add_executable(app
        src/config/Configuration.cpp
        src/db/JsonFileDatabase.cpp
        src/engine/expression/AndExpression.cpp
        src/engine/expression/BinaryExpression.cpp
        src/engine/expression/ConstantExpression.cpp
        src/engine/expression/EqualExpression.cpp
        src/engine/expression/GreaterEqualExpression.cpp
        src/engine/expression/GreaterExpression.cpp
        src/engine/expression/LessEqualExpression.cpp
        src/engine/expression/LessExpression.cpp
        src/engine/expression/NotEqualExpression.cpp
        src/engine/expression/OrExpression.cpp
        src/engine/expression/ValueConverter.cpp
        src/engine/expression/ValueFactory.cpp
        src/engine/expression/VariableExpression.cpp
        src/engine/lexer/Lexer.cpp
        src/engine/Location.cpp
        src/engine/ParseException.cpp
        src/engine/Token.cpp
        src/engine/TokenType.cpp
        src/ui/ExpressionPrettyPrinter.cpp
        src/ui/UserInterface.cpp
        src/Application.cpp
        src/main.cpp
)

target_include_directories(app PRIVATE include)

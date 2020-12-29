cmake_minimum_required(VERSION 3.0)

project (infix2postfix)


include_directories(include)

# add_definitions(-DDEBUG)
add_executable( test-infix2postfix test/test-infix2postfix.cpp)

cmake_minimum_required(VERSION 3.0)

project (postfix-calculator)


include_directories(include)

#add_definitions(-DDEBUG)
add_executable( test-postfix-calculator test/test-postfix-calculator.cpp)

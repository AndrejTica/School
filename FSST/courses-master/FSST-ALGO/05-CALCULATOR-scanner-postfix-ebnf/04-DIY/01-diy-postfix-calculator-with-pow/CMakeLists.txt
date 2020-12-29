cmake_minimum_required(VERSION 3.0)

project (postfix-calculator-with-pow)


include_directories(include)

#add_definitions(-DDEBUG)
add_executable( test-scanner test/test-scanner.cpp)
add_executable( test-infix2postfix test/test-infix2postfix.cpp)
add_executable( test-postfix-calculator test/test-postfix-calculator.cpp)

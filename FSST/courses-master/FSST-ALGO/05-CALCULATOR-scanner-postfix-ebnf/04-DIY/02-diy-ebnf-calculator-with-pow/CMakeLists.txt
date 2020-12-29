cmake_minimum_required(VERSION 3.0)

project (ebnf-calculator-pow)


include_directories(include)

#add_definitions(-DDEBUG)
add_executable( test-scanner test/test-scanner.cpp)
add_executable( test-ebnf-calculator test/test-ebnf-calculator.cpp)

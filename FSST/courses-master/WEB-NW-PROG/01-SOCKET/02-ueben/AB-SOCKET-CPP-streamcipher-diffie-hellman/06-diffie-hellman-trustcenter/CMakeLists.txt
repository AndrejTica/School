cmake_minimum_required(VERSION 3.0)
project (trustcenter DESCRIPTION "trustcenter" LANGUAGES CXX)

include_directories("include")

set (SOURCES 
    "src/Socket.cpp"
    "src/ServerSocket.cpp")

add_executable( trustcenter-main src/trustcenter-main.cpp ${SOURCES})

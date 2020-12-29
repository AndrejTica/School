cmake_minimum_required(VERSION 3.0)
project (socket DESCRIPTION "socket-cpp" LANGUAGES CXX)

include_directories("include")

set (SOURCES 
    "src/Socket.cpp"
    "src/ServerSocket.cpp"
    "src/ClientSocket.cpp")

add_executable( server src/simple_server_main.cpp ${SOURCES})
add_executable( client src/simple_client_main.cpp ${SOURCES})

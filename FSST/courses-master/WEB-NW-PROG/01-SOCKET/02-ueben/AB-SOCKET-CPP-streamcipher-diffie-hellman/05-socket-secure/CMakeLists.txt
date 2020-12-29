cmake_minimum_required(VERSION 3.0)
project (socket_secure DESCRIPTION "socket secure" LANGUAGES CXX)

include_directories("include")

set (SOURCES 
    "src/Socket.cpp"
    "src/ServerSocket.cpp"
    "src/ClientSocket.cpp"
    "src/ClientSocket_secure.cpp"
    "src/ServerSocket_secure.cpp"
    )

add_compile_definitions(DEBUG)

add_executable( server src/simple_server_main.cpp ${SOURCES})
add_executable( client src/simple_client_main.cpp ${SOURCES})

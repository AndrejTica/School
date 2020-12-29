cmake_minimum_required(VERSION 3.0)
project (alice_and_bob LANGUAGES CXX)

include_directories("include")

set (SOURCES 
    "src/Socket.cpp"
    "src/ServerSocket.cpp"
    "src/ServerSocket_secure.cpp"
    "src/ClientSocket.cpp"
    "src/ClientSocket_secure.cpp"
    )

add_compile_definitions(DEBUG)

add_executable( alice src/alice.cpp ${SOURCES})
add_executable( bob src/bob.cpp ${SOURCES})

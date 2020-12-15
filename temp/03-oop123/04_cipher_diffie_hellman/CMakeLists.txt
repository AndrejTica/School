cmake_minimum_required(VERSION 3.0)
project (cipher)

include_directories("include")

add_executable( test-xorsubstitution  test/test-xorsubstitution.cpp src/cipher.cpp src/xorsubstitution.cpp)

#add_executable( test-addsubstitution  test/test-addsubstitution.cpp src/cipher.cpp src/addsubstitution.cpp)

add_executable( test-streamcipher  test/test-streamcipher.cpp src/cipher.cpp src/xorsubstitution.cpp src/streamcipher.cpp)

#add_executable( test-diffie-hellman  test/test-diffie-hellman.cpp src/cipher.cpp src/xorsubstitution.cpp src/streamcipher.cpp src/dhcipher.cpp)


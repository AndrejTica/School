# AUfGABE

cipher-diffie-hellman

<section>

1. read: AB-CPP-OOP-krypto-cipher.pdf

- <https://gitlab.com/4me/courses/-/blob/master/CPP/03-oop123-class-association-inheritance/02-ueben/AB-CPP-OOP-krypto-cipher.pdf>

---

1. test-xorsubstitution.cpp

- files:
  - cipher.h, cipher.cpp
  - xorsubstitution.h , xorsubstitution.h
  - test-xorsubstitution.cpp
  
---

2. test-addsubstitution.cpp

- files:
  - cipher.h, cipher.cpp
  - addsubstitution.h , addsubstitution.h
  - test-addsubstitution.cpp
  
---

3. test-streamcipher.cpp

- files:
  - cipher.h, cipher.cpp
  - xorsubstitution.h , xorsubstitution.h
  - streamcipher.cpp, streamcipher.h
  - test-streamcipher.cpp
  
---

4. test-diffie-hellman.cpp

- files:
  - cipher.h, cipher.cpp
  - xorsubstitution.h , xorsubstitution.h
  - streamcipher.cpp, streamcipher.h
  - dhcipher.cpp, dhcipher.h
  - test-diffie-hellman.cpp
  
---

5. build

``` bash
mkdir build
cd build
cmake ..
make
./test-xorsubstitution
./test-addsubstitution
./test-streamcipher
./test-diffie-hellman
```

</section>

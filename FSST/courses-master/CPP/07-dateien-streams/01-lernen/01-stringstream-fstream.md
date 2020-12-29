# Streams: stringstream, fstream
1. Study <https://gitlab.com/4me/courses/blob/master/CPP/07-dateien-streams/01-lernen/dateien-streams.odt>
2. see below for a short description/hints of streams


## 1. stringstream
<http://www.cplusplus.com/reference/sstream/>
```cpp
#include <sstream>
using namespace std;
```


### 1.1. ostringstream
```cpp
ostringstream os;
os << 123 << " hello " << endl;
string s= os.str();
```


### 1.2. istringstream, getline
```cpp
string s="ABC:123:def";
string split;

istringstream is(s);
getline(is, split, ':');
cout << split;

getline(is, split, ':');
cout << split;

getline(is, split, ':');
cout << split;
```


## 2. fstream
<http://www.cplusplus.com/reference/fstream/>

```cpp
#include <fstream>
using namespace std;
```


### 2.1. ifstream
```cpp
// print the content of a text file.
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

int main () {
  std::ifstream ifs;

  ifs.open ("test.txt", std::ifstream::in);

  char c = ifs.get();

  while (ifs.good()) {
    std::cout << c;
    c = ifs.get();
  }

  ifs.close();

  return 0;
}
```



### 2.2. ofstream
```cpp
// ofstream::open / ofstream::close
#include <fstream>      // std::ofstream

int main () {

  std::ofstream ofs;
  ofs.open ("test.txt", std::ofstream::out | std::ofstream::app);

  ofs << " more lorem ipsum";

  ofs.close();

  return 0;
}
```


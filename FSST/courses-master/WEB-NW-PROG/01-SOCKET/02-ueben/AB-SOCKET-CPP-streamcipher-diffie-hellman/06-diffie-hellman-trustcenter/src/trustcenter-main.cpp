// trustcenter-main.cpp
/*
"GET:NG"
        "123:456"

"ADD:PK:BOB:123"
        "200 OK"

"GET:PK:BOB"
        "123"
        "-402"

"?"
        "-401"

./test-trustcenter.exe 4444 5 7

*/
#include "trustcenter.h"

// ht
int port = 30000;
string n = "5";
string g = "7";

int main(int argc, char *argv[]) {

  TrustCenter trustcenter(port, n, g);

  trustcenter.accept();

  return 0;
}

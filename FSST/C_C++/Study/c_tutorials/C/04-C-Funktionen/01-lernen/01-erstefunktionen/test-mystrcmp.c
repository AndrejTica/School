// test-mystrcmp.c
// N.N
#include <stdio.h>
#include <assert.h>  // see: http://www.cplusplus.com/reference/cassert/assert/

// Funktions-Prototype
int mystrcmp(const char s[], const char t[]);

int main(){
	printf("TESTE: int mystrcmp(const char s[], const char t[]);\n");
	assert(mystrcmp("","") == 0 );
	assert(mystrcmp("a","a") == 0 );
	assert(mystrcmp("abc","abc") == 0 );
	// ----
	assert(mystrcmp("","a")== -1);
	assert(mystrcmp("","abc")== -1);
	assert(mystrcmp("a","ab")== -1);
	assert(mystrcmp("a","abc")== -1);
	// -----
	assert(mystrcmp("a","")== 1);
	assert(mystrcmp("abc","")== 1);
	assert(mystrcmp("ab","a")== 1);
	assert(mystrcmp("abc","a")== 1);
	// -----
	assert(mystrcmp("abc","abcd")== -1);
	assert(mystrcmp("abcd","abc")== 1);
	// ----
	assert(mystrcmp("A","Z")== -1);
	assert(mystrcmp("Z","A")== 1);
	assert(mystrcmp("ABC","ZBC")== -1);
	assert(mystrcmp("ZBC","ABC")== 1);
	printf("ALLES OK: wenn dieser Text auf der Konsole erscheint\n");

	return 0;
}

// Funktions-Implementierung
int mystrcmp(const char s[], const char t[]){
	// todo ??????????????????????????
	return 0;
}


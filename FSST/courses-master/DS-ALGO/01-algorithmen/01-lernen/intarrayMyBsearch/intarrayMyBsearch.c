// ahofmann, 2017
//
// intarrayMyBsearch.c
//
// Binary Search in Arrays
//

#include <stdio.h>

// iterative Version
int iter_binsearch(int key, int* a; int l, int r){
	//????????????????????????
	return -1;
}

// recursive Version
int rec_binsearch(int key, int* a; int l, int r){
	//???????????????????????????????
	return -1;
}


#define LEN 5

int main(){
	int arr[LEN]={1,18,25,70,900};
	int key=70;
	int idx;
	int i, algo;
	
	printf("\nint-Array ...\n ");
	for( i=0; i< LEN; i++)
		printf("%4i ", arr[i]);

	printf("\n1. recursive binary Search");
	printf("\n2. iterative binary Search\n");
	scanf("%i", &algo);
	
	if (algo== 1)
		idx= rec_binsearch(key, arr, 0, LEN-1);
	else
		idx= iter_binsearch(key, arr, 0, LEN-1);
	
	if (idx==-1)
		printf("\n%i not found\n" , key);
	else
		printf("\n%i found at index %i\n" , key, idx);
	
	return 0;
}

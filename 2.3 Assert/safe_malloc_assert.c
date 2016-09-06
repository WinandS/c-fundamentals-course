#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int * safe_calloc(size_t num, size_t size);

int main(int argc, char * argv[]){
	int * p = safe_calloc(1024*1024*1024*1024, sizeof(int));
	free(p);
	exit(0);
}


int * safe_calloc(size_t num, size_t size){
	int * p = calloc(num, size);
	assert(p==NULL&&"\nOh noes. It failed.,\n");	
	return p;
}


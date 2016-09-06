#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
	int size = 1000;
	int * a = calloc(size, sizeof(int));
	int i;
	for(i=0;i<size;i+=5){
		printf("%p\n",&a[i]);
	}

	free(a);
}

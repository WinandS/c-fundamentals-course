#include <stdio.h>
int main(int argc, char * argv[]){
	int i = 0;
	printf("Hello Tass!\n"
		"This is the execution name %s\n",argv[i]);
	printf("The number of arguments is: %i\nAll given arguments are:\n",argc);
	for(i=1;i<argc;i++){
		printf("argument %i:%s\n",i ,argv[i]);
	}
	printf("The number of arguments is: %i\nAll given arguments in reverse order are:\n",argc);
	for(i=argc-1;i>1;i--){
		printf("argument %i:%s\n",i ,argv[i]);
	}
}

#include <stdio.h>
#include <unistd.h>

int calculate_length(const char * string);

int main(int argc, char * argv[]){
	int i;
	for(i=1;i<argc;++i){
		printf("The length of argument %i: \"%s\" is %i\n",i ,argv[i], calculate_length(argv[i]));
	}
}

int calculate_length(const char * string){
	const char * ptr = string;
	int i = 0;
	while(*ptr++ != '\0'){
		i++;
	}
	return i;
}

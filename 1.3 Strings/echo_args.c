#include <stdio.h>
#include <string.h>

char * to_upper(char * s){
	int change = 'A'-'a';
	char * ptr = s;
	int i;
	for (i = 0; i < strlen(s); i++){
		s[i]+=change;
	}
	return s;
}

int main(int argc, char * argv[]){
	int i;
	for(i=1;i<argc;i++){
		printf("Argument %i: %s\n"
			"Length: %i\n",i ,to_upper(argv[i]),(int) strlen(argv[i]));
	}
}

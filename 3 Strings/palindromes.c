#include <stdio.h>
#include <string.h>
#include <ctype.h>

char * palindrome(char * arg);

int main(int argc, char * argv[]){
	int i;
	for(i=1;i<argc;i++){
		printf("Argument %i: \"%s\" is %sa palindrome!\n",i ,argv[i] , palindrome(argv[i]));
	}
}

char * palindrome(char * arg){
	int len = strlen(arg);
	int i=0;
	while(i<=len/2 && (toupper(arg[i])==toupper(arg[len-1-i]))){
		i++;
	}
	i--;
	if(i==len/2)
		return "";
	else
		return "not ";
}

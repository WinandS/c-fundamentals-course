#include <stdio.h>
#include <string.h>

char * check_syntax(int argc, char* argv[]){
	if(argc<4){ // check whether the user provided enough arguments
		return "Not enough arguments\n";
	} else{ //check whether the operand is known
		char * operations [] = { "+", "-", "*", "/" };
		int is_known = 0;
		int j;
		int len = sizeof(operations)/sizeof(operations[0]);
		for(j=0; j<len; j++){
			if(strcmp(argv[1],operations[j])==0){
				is_known = 1;
			}
		}
		if(!is_known){
			return "Operator not known\n";
		}else{ //check whether the arguments are of length 1
			int i=0;
			for(i=1;i<argc;i++){
				if(strlen(argv[i])>1)
					return "Arguments do not meet specifications\n";
			}
		}
	return argv[1];
	}
}

int calculate(char * op, int a, int b){
	char * operations [] = { "+", "-", "*", "/" };
	int j;
	int len = sizeof(operations)/sizeof(operations[0]);
	for(j=0; j<len; j++){
		if(strcmp(op,operations[j])==0){
			break;
		}
	}
	switch(j){
	case 0: return a+b;
	case 1: return a-b;
	case 2: return a*b;
	case 3: return a/b;
	}
}

int main(int argc, char* argv[]){
	char * result = check_syntax(argc, argv);
	int len = sizeof(*result)/sizeof(char);
	if(len>1){
		printf("%s\n",result);
	} else{
		//calculate
		int i=2;
		int a= atoi(argv[i]);

		for(i=3;i<argc;i++){

			int b= atoi(argv[i]);
			a = calculate(result, a, b);
		}
		printf("%i\n",a);
	}
}


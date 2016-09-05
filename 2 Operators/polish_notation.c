#include <stdio.h>
#include <string.h>

char * operations [] = { "+", "-", "*", "/", "<<", ">>", "||" };
int len = sizeof(operations)/sizeof(operations[0]);

char * check_syntax(int argc, char* argv[]){
	if(argc<4){ // check whether the user provided enough arguments
		return "Error: Not enough arguments\n";
	} else{ //check whether the operand is known
		int is_known = 0;
		int j;
		for(j=0; j<len; j++){
			if(strcmp(argv[1],operations[j])==0){
				is_known = 1;
			}
		}
		if(!is_known){
			return "Error: Operator not known\n";
		}else{ //check whether the arguments are of numbers
			int i=0;
			for(i=1;i<argc;i++){
				if(0) //check whether or not the argument is a number
					return "Error: Arguments do not meet specifications\n";
			}
		}
	return argv[1];
	}
}

int calculate(char * op, int a, int b){
	int j;
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
	case 4: return a<<b;
	case 5: return a>>b;
	case 6: return a|b;
	}
}

int read(char * arg){
//	return atol(arg);
	int ret;
	if(*arg == '0'){
		if(*(arg+1) == 'x'){
			ret = (int) strtol(arg, NULL , 16); //hexadecimal
		}
		ret = (int) strtol(arg, NULL, 8); //octal
	}
	ret = (int) atol(arg); //decimal
	printf("%i\n", ret);
	return ret;
}


int main(int argc, char* argv[]){
	char * result = check_syntax(argc, argv);
	int len = sizeof(*result)/sizeof(char);
	if(len>5){
		printf("%s\n",result);
	} else{

		//calculate
		int i=2;
		int a= read(argv[i]);

		for(i=3;i<argc;i++){

			int b= read(argv[i]);
			a = calculate(result, a, b);
		}
		printf("%i\n",a);
	}
}


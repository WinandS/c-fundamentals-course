#include <stdio.h>
#include <stdlib.h>

double c2k(double c);
double f2k(double f);
double k2c(double k);
double k2f(double k);
double c2f(double c);
double f2c(double f);

int main(int argc, char * argv[]){
	double T = (strtod(argv[2],NULL));
	printf("%lf\n",T);
	char * commands[] = {"c2k","f2k","k2c","k2f","c2f","f2c"};
	char * p = commands[0];
	int i = 0;
	while(*p!='\0'&& strcmp(argv[1],commands[i])){
		i++;
		p=commands[i];
	}
	printf("%s\n",p);
	printf("%i\n",i);
	switch(i){
		case 0: 
			printf("%lf\n",c2k(T));
			break;
		case 1: 
			printf("%lf\n",f2k(T));
			break;
		case 2:	
			printf("%lf\n",k2c(T));
			break;
		case 3: 
			printf("%lf\n",k2f(T));
			break;
		case 4: 
			printf("%lf\n",c2f(T));
			break;
		case 5: 
			printf("%lf\n",f2c(T));
			break;
		default:
			printf("command not supported\n"); 
	}
}

double c2k(double c){
	return c + 273.15;
}
double f2k(double f){
	return c2k((f-32.0)*5.0/9.0);
}
double k2c(double k){
	return k-273.15;
}
double k2f(double k){
	return c2f(k2c(k));
}
double c2f(double c){
	return c*9.0/5.0+32.0;
}
double f2c(double f){
	return k2c(f2k(f));
}


#include <stdio.h>

int main(int argc, int argv[]){
	char c = 'a';
	int i = 1;
	double d = 1.0;
	float f = 1000.1000;

	char * cp = &c;
	int * ip = &i;
	double * dp = &d;
	float * fp = &f;

	* cp = 'b';
	* ip = 2;
	* dp = 2.0;
	* fp = 2000.2000;
	
	printf("char pointer c points to address %p, which holds value %c\n",cp, *cp);
	printf("int pointer i points to address %p, which holds value %i\n",ip, *ip);
	printf("double pointer d points to address %p, which holds value %f\n",dp, *dp);
	printf("float pointer f points to address %p, which holds value %f\n",fp, *fp);
}

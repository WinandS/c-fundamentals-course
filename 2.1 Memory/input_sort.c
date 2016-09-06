
#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b);

int main(int argc, char * argv[]){
	printf("Any numbers you input here will be sorted.\n"
		"How many numbers will you enter?\n");
	int n;
	scanf("%i",&n);
	printf("Enter your numbers below.\n");
	int i;
	double * numbers = calloc(n, sizeof(double));
	for(i=0;i<n;i++){
		scanf("%lf",numbers+i);
	}

	qsort (numbers, n, sizeof(double), compare);

	printf("The sorted numbers will be printed below.\n");
	for(i=0;i<n;i++){
		printf("%lf\n",*(numbers+i));
	}
	

}
int compare(const void * a, const void * b){
	return (*(double*) a - *(double*) b);
}

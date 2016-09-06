#include <stdio.h>

int max(int numbers[]);

int main(int argc, int argv[]){
	int amount;
	printf("How many numbers?\n");
	scanf("%d", &amount);
	int numbers[amount];
	int i;
	for(i=0;i<amount;i++){
		scanf("%d", &numbers[i]);
	}
	printf("Thanks!\nHere is the max number of your numbers: %i.\n",max(numbers));
}


int max(int * numbers){
	int len =  sizeof(numbers)/sizeof(numbers[0]);
	int i;
	int max = numbers[0];
	int min = max;
	for(i=1;i<len;i++){
		if(numbers[i]>max)
			max = numbers[i];
		if(numbers[i]<min)
			min = numbers[i];
	}
	return max;
}

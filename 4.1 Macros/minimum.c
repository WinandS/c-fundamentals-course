#include <stdio.h>

#define minimum2(x,y) ((x)<(y)?(x):(y))
#define minimum3(x, y, z) minimum2((x), minimum2((y),(z)))

int main(int argc, char * argv[]){
	int a = 1;
    int b = 2;
    int c = 3;
    printf("%i\n", minimum3(a, b, c));
}

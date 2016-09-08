#include <stdio.h>

#define swap(t, a, b) do { \
    t c = a;            \
    a = b;                 \
    b = c;              \
} while (0)


int main()
{
    int x = 5;
    int y = 10;

    printf("%i:%i\n", x, y);
    swap(int, a, b);
    printf("%i:%i\n", x, y);
}
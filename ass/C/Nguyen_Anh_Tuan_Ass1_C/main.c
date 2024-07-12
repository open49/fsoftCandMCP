#include <stdio.h>
#include "fibonacci.h"

int main()
{
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    printf("%d", Fibonacci(n));
    return 1;
}


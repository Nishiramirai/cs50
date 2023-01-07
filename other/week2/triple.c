// Code example from score short

#include <stdio.h>

int triple(int x);

int main(void)
{
    int result = triple(5);
    printf("%i\n", result);
}


int triple(int x)
{
    return x * 3;
}
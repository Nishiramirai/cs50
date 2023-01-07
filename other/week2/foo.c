// Code example from scope short
#include <stdio.h>

int triple(int x);

int main(void)
{
    int foo1 = 4;
    triple(foo1);
    printf("foo1: %i\n", foo1);

    int foo2 = 4;
    foo2 = triple(foo2);
    printf("foo2: %i\n", foo2);
}

int triple(int x)
{
    return x *= 3;
}
// Code example from scope short

#include <stdio.h>

float global = 0.5050;

void triple(void);


int main(void)
{
    triple();
    printf("%f\n", global);
}

void triple (void)
{
    global *= 3;
}
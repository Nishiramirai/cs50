#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("adress: %p\nvalue: %i \n", p, *p);
}
#include <stdio.h>

void meow(void);

int main(void)
{
    for (int i = 0; i < 6; i++)
    {
        meow();
    }
}

void meow(void)
{
    printf("meow\n");
}
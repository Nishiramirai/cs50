#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int("How many times you want to meow? ");
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
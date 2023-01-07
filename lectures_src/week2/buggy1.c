#include <stdio.h>
#include <cs50.h>

int get_negative_int();

int main(void)
{
    int num = get_negative_int();
    printf("%i\n", num);
}


int get_negative_int()
{
    int n;
    do
    {
        n = get_int("Negative integer: ");
    }
    while (n >= 0);
    return n;
}
#include <cs50.h>
#include <stdio.h>

int get_number_between(int min, int max);
void print_pyramid(int n);


int main(void)
{
    // Get size of the pyramid
    int n = get_number_between(1, 8);

    // Print pyramid
    print_pyramid(n);
}


// Prompt for integer number until it will be correct and return it
int get_number_between(int min, int max)
{
    int num;
    do
    {
        num = get_int("Height: ");
    }
    while (num < min || num > max);

    return num;
}


// Print pyramid with specified size
void print_pyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Print left part
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");

        // Print right part
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
// Print right-aligned pyramid

#include <cs50.h>
#include <stdio.h>

int get_size(int min_size, int max_size);
void print_pyramid(int n);


int main(void)
{
    // Get size of pyramid
    int n = get_size(1, 8);

    // Print pyramid
    print_pyramid(n);
}


// Get user input until it will be correct
int get_size(int min_size, int max_size)
{
    int size;

    do
    {
        size = get_int("Positive number: ");
    }
    while (size < min_size || size > max_size);

    return size;
}


// Print pyramid
void print_pyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Print spaces of current row
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        // Print hashs of current row
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Go to the next line
        printf("\n");
    }
}
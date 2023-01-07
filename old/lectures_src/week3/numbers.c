#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};
    int num = get_int("Enter number: ");

    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == num)
        {
            printf("Found at index %i\n", i);
            return 0;
        }
    }

    printf("Not found\n");
    return 1;
}
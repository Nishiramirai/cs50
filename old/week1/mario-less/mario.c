#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int get_integer_from_1_to_8(void);
    void print_pyramid(int n);


    int n = get_integer_from_1_to_8();
    print_pyramid(n);

}

//Gets the user input and stores it inside variable n
int get_integer_from_1_to_8(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    return n;
}

//Prints pyramid with a given size
void print_pyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i + 1; j--)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    while (true)
    {
        char c = get_char("Do you agree? (y/n)");

        if (c == 'Y' || c == 'y')
        {
            printf("Agreed\n");
            break;
        }
        else if (c == 'N' || c == 'n')
        {
            printf("Not agreed\n");
            break;
        }
    }
}
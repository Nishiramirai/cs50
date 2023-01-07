// Practice problem from week 2 functions short

#include <stdio.h>
#include <cs50.h>

bool valid_triangle(int a, int b, int c);

int main(void)
{
    int a = 3;
    int b = 4;
    int c = 5;

    if (valid_triangle(a, b, c))
    {
        printf("Triangle is valid\n");
    }
    else
    {
        printf("Triangle is invalid\n");
    }
}


bool valid_triangle(int a, int b, int c)
{
    bool sizes_are_positive = a > 0 && b > 0 && c > 0;
    bool sum_are_valid = a + b > c && a + c > b && c + b > a;

    return sizes_are_positive && sum_are_valid;
}
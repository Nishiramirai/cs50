#include <stdio.h>
#include <cs50.h>

#define PI 3.14159265


int main(void)
{
    int radius = get_int("Enter radius of circle: ");
    printf("Length of this circle is: %f\n", 2 * radius * PI);
}
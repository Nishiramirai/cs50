#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Gets name from the user and welcoming him
    string name = get_string("What is your name?\n");
    printf("Hello, %s\n", name);
}
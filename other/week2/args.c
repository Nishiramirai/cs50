#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Try: argc --help for more information\n");
        return 1;
    }

    if (strcmp(argv[1], "--help") == 0)
    {
        printf("-- help   display the help and exit\n");
        printf("--version output verison information and exit\n");
        return 0;
    }

    if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "-ver") == 0 || strcmp(argv[1], "-version") == 0)
    {
        printf("Version: 0.0.1\n");
        return 0;
    }

    else
    {
        printf("Incorrect usage. Try: argc --help for more information\n");
        return 1;
    }
}
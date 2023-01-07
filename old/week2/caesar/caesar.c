#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    // Check for valid command line argument count
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Checking key
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Converting valid key from string to int
    int key = atoi(argv[1]);

    //get a string from the user
    string plaintext = get_string("plaintext: ");

    //print encrypted text
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");


    return 0;
}

//check that string contains only digits
bool only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }

    return true;
}

//encrypt char and return it
char rotate(char c, int key)
{
    if (isalpha(c))
    {
        //encrypt uppercase
        if (isupper(c))
        {
            c -= 'A';
            c += key;
            c %= 26;
            return (c + 'A');

        }

        //encrypt lowercase
        else
        {
            c -= 'a';
            c += key;
            c %= 26;
            return (c + 'a');
        }
    }
    else
    {
        return c;
    }
}
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string num);
string cipher(string text, int key);


int main(int argc, string argv[])
{
    // If command line argument is invalid, print error message and return 1
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    // Get text from user
    string text = get_string("plaintext: ");

    // Print ciphered text
    printf("ciphertext: %s\n", cipher(text, key));
    return 0;
}


// Check that number contains only digits
bool only_digits(string num)
{
    for (int i = 0, n = strlen(num); i < n; i++)
    {
        if (!isdigit(num[i]))
        {
            return false;
        }
    }
    return true;
}


// Cipher text and return result
string cipher(string text, int key)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (text[i] - 'A' + key) % 26 + 'A';
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (text[i] - 'a' + key) % 26 + 'a';
        }
    }

    return text;
}
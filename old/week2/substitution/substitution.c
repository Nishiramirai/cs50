#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool is_key_valid(string key);
void print_substitution_cipher(string plaintext, string key);

int main(int argc, string argv[])
{
    //command line argument handle
    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }

    string key = argv[1];

    //key validation
    if (!is_key_valid(key))
    {
        printf("Usage: ./substitution key");
        return 1;
    }

    //get text from user
    string plaintext = get_string("plaintext: ");


    //encypt and print new text
    print_substitution_cipher(plaintext, key);
    return 0;
}

//key validation, returns true if key is valid, else false
bool is_key_valid(string key)
{
    int len = strlen(key);

    //check length of a key
    if (len != 26)
    {
        return false;
    }

    //check is all character of key alphabetical
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }

    //check for duplicates
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }
    return true;

}

void print_substitution_cipher(string plaintext, string key)
{
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            printf("%c", tolower(key[plaintext[i] - 97]));
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            printf("%c", toupper(key[plaintext[i] - 65]));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
}
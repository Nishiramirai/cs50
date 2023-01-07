#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool is_key_valid(string key);
string cipher(string plaintext, string key);

int main(int argc, string argv[])
{
    // Key validation
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    if (!is_key_valid(key))
    {
        printf("Key is invalid. Key have 26 alphabetic characters and contain each other exactly once\n");
        return 1;
    }

    // Get plaintext
    string plaintext = get_string("plaintext: ");

    // Print ciphertext
    printf("ciphertext: %s\n", cipher(plaintext, key));
}


// Validate key, return true if key is valid, false if not
bool is_key_valid(string key)
{
    // Check key length
    int length = strlen(key);
    if (length != 26)
    {
        return false;
    }

    // Check that chars are alphabetic and appear only once
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        for (int j = 0; j < i; j++)
        {
            if (key[j] == key[i])
            {
                return false;
            }
        }
    }

    return true;
}


// Cipher the text by substition
string cipher(string plaintext, string key)
{
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char current_char = plaintext[i];
        if (current_char >= 'a' && current_char <= 'z')
        {
            int alphabet_position = current_char - 'a';
            plaintext[i] = tolower(key[alphabet_position]);
        }
        else if (current_char >= 'A' && current_char <= 'Z')
        {
            int alphabet_position = current_char - 'A';
            plaintext[i] = toupper(key[alphabet_position]);
        }
    }

    return plaintext;
}
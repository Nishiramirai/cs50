// Code example from debugging short
#include <stdio.h>
#include <cs50.h>
#include <string.h>

bool check_phrase(string phrase);

int main(void)
{
    string phrase = get_string("What's the secret phrase? ");

    bool correct = check_phrase(phrase);

    if (correct == true)
    {
        printf("Come on in!\n");
    }
}


bool check_phrase(string phrase)
{
    string password = "Please";

    return strcmp(phrase, password) == 0;
}
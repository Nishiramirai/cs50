#include <stdio.h>
#include <cs50.h>
#include <string.h>

void printlower(string s);
void printupper(string s);


int main(void)
{
    string s1 = get_string("Type a string you want to lower: ");
    string s2 = get_string("Type a string you want to upper: ");

    printf("Lower: ");
    printlower(s1);

    printf("Upper: ");
    printupper(s2);
}


void printlower(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            printf("%c", s[i] + 32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
        printf("\n");
}


void printupper(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
        {
            printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}



// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool haslower = false;
    bool hasupper = false;
    bool hasnumber = false;
    bool hassymbol = false;

    for (int i = 0, n = strlen(password); i < n; i++)
    {
        if (islower(password[i]))
        {
            haslower = true;
        }
        if (isupper(password[i]))
        {
            hasupper = true;
        }
        if (isdigit(password[i]))
        {
            hasnumber = true;
        }
        if (!isalnum(password[i]))
        {
            hassymbol = true;
        }
    }

    return haslower && hasupper && hasnumber && hassymbol;
}

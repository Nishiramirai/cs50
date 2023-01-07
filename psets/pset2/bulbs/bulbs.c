#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);


int main(int argc, string argv[])
{
    string msg;

    // If there is a command line argument, use it, ask for a prompt if not
    if (argc == 2)
    {
        msg = argv[1];
    }
    else
    {
        msg = get_string("Message: ");
    }

    // Print message in binary form as a bulbs
    for (int i = 0, n = strlen(msg); i < n; i++)
    {
        // Make a array that contains current character in binary form
        int current_byte[BITS_IN_BYTE] = {0, 0, 0, 0, 0, 0, 0, 0};
        int current_number = msg[i];

        // Convert character into array of binary digits
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            int current_binary = (int) pow(2, BITS_IN_BYTE - j - 1);
            if (current_number >= current_binary)
            {
                current_byte[j] = 1;
                current_number -= current_binary;
            }
            else
            {
                current_byte[j] = 0;
            }
        }

        // Print bulbs
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            print_bulb(current_byte[j]);
        }
        printf("\n");
    }
}


void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

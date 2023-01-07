#include <cs50.h>
#include <stdio.h>

bool is_card_valid(long card_number);
string get_card_company(long card_number);


int main(void)
{
    // Get number from user
    long card_number = get_long("Number: ");
    string card_company = "INVALID";

    // Calculate checksum
    if (is_card_valid(card_number))
    {
        // Check for card length and starting digits
        card_company = get_card_company(card_number);
    }

    // Print AMEX, MASTERCARD, VISA or INVALID
    printf("%s\n", card_company);
}


// Card number validation user Luhn's Algorithm
bool is_card_valid(long card_number)
{
    //Mulityply every other digit from second to last by 2, and then add those products' digits together
    int first_sum = 0;
    for (long i = 10; i < card_number; i *= 100)
    {
        long current_digit = (card_number % (i * 10) / i) * 2;
        first_sum += current_digit / 10 + current_digit % 10;
    }

    // Get sum of digits that weren't multiplies by 2
    int second_sum = 0;
    for (long i = 1; i < card_number; i *= 100)
    {
        long current_digit = card_number % (i * 10) / i;
        second_sum += current_digit;
    }

    int total_sum = first_sum + second_sum;

    return (total_sum % 10 == 0);
}


// Get name of the company that owns this card, returns "INVALID" if not one of them
string get_card_company(long card_number)
{
    if (card_number / 100000000000000 == 51 ||
        card_number / 100000000000000 == 52 ||
        card_number / 100000000000000 == 53 ||
        card_number / 100000000000000 == 54 ||
        card_number / 100000000000000 == 55
       )
    {
        return "MASTERCARD";
    }
    else if (card_number / 10000000000000 == 34 ||
             card_number / 10000000000000 == 37)
    {
        return "AMEX";
    }
    else if (card_number / 1000000000000000 == 4 ||
             card_number / 1000000000000 == 4)
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}
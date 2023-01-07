#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //declaring prototypes of functions
    long get_card_number(void);
    bool checksum(long card_number);
    string get_card_company(long card_number);

    //get card number
    long card_number = get_card_number();

    //if number is valid, find whose card it is (AS, Visa, Mastercard) and print it
    if (checksum(card_number))
    {
        string company = get_card_company(card_number);
        printf("%s", company);
    }
    //if number is not valid, print it
    else
    {
        printf("INVALID\n");
    }
}


long get_card_number()
{
    long card_number;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 1000000000);

    return card_number;
}


//1. Начиная с предпоследей цифры, умножить каждую вторую цифру, и затем сложить каждую получившуюся цифру (именно цифру, а не число)
//2. К получившейся сумме добавить сумму всех цифр, которые не были умножены на 2 (то есть каждое второе число, начиная с последнего)
//3. Если получившееся число кратно 10, то номер карты валиден, в другом случае нет
bool checksum(long card_number)
{
    int first_sum = 0;
    for (long i = 100; i < card_number * 10; i *= 100)
    {
        int some_int = (card_number % i) / (i / 10) * 2;
        if (some_int >= 10)
        {
            first_sum += ((some_int % 100 / 10) + some_int % 10);
        }
        else
        {
            first_sum += some_int;
        }
    }

    int second_sum = 0;
    for (long i = 10; i < card_number * 10; i *= 100)
    {
        int some_int = (card_number % i) / (i / 10);
        if (some_int >= 10)
        {
            second_sum += ((some_int % 100 / 10) + some_int % 10);
        }
        else
        {
            second_sum += some_int;
        }
    }
    return ((first_sum + second_sum) % 10 == 0);
}


string get_card_company(long card_number)
{
    //If card number have 15 digits and stars with 34 or 37, it's American Express
    if ((card_number / 10000000000000 == 34) ||
        (card_number / 10000000000000 == 37))
    {
        return "AMEX\n";
    }

    //If card number have 13 or 16 digits and starts with 4, it's Visa
    else if (card_number / 1000000000000000 == 4 ||
             card_number / 1000000000000 == 4)
    {
        return "VISA\n";
    }

    //If card number have 16 digits and starts with 51, 52, 53, 54, or 55, it's Mastercard
    else if ((card_number / 100000000000000 == 51) ||
             (card_number / 100000000000000 == 52) ||
             (card_number / 100000000000000 == 53) ||
             (card_number / 100000000000000 == 54) ||
             (card_number / 100000000000000 == 55))
    {
        return "MASTERCARD\n";
    }

    //If none of the conditions are met, than it's invalid card number
    else
    {
        return "INVALID\n";
    }
}
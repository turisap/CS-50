#include <cs50.h>
#include <stdio.h>

// A programm to check if a credit card number is a valid one using Luhn’s Algorithm.

int main(void)
{
    bool valid;
    long card_number;
    int counter = 1;
    int multiplied_sum = 0;
    int not_multiplied_sum = 0;
    int last_two;
    int visa_valid_length = 0;
    string card_type;

    do
    {
        card_number = get_long("Number: ");
    } while (!card_number);

    visa_valid_length = card_number > 1000000000000000;

    do
    {
        int reminder = card_number % 10;
        card_number = (card_number - reminder) / 10;

        if (counter % 2 == 0)
        {
            int doubled = reminder * 2;

            if (doubled >= 10)
            {
                multiplied_sum += (doubled % 10 + 1);
            }
            else
            {
                multiplied_sum += doubled;
            }
        }
        else if (counter % 2 == 1)
        {
            not_multiplied_sum += reminder;
        }

        if (card_number < 100 && card_number >= 10)
        {
            last_two = card_number;
        }

        counter++;

    } while (card_number > 0);

    valid = (multiplied_sum + not_multiplied_sum) % 10 == 0 ? true : false;
    int last_one = (last_two - last_two % 10) / 10;

    if (valid && (last_two == 34 || last_two == 37))
    {
        card_type = "AMEX";
    }
    else if (valid && (last_two >= 51 && last_two <= 55))
    {
        card_type = "MASTERCARD";
    }
    else if (valid && last_one == 4 && visa_valid_length)
    {
        card_type = "VISA";
    }
    else
    {
        card_type = "INVALID";
    }

    printf("%s\n", card_type);
}

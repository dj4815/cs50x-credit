// Currently not working properly for some credit card numbers, coming back to this later as it is an optional exercise
// TODO: Prompt user for credit card number, then check which type of credit card it is and print the result
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for input
    long cc_number = get_long("Number: ");

    // Initialize variables and arrays
    int counter = 0;
    int sum_1 = 0;
    int sum_2 = 0;
    int total = 0;

    // While the number is not 0:
    long checksum = cc_number;
    while (checksum != 0)
    {
        // Remove the last digit to start from the second to last
        checksum /= 10;

        // Use the modulus operator (%) to get the last digit of the number.
        int last_digit = checksum % 10;

        // If the counter is even & last digit times two is greater than 9,
        if (counter % 2 == 0 && (last_digit * 2) > 9)
        {
            // Extract digit 1
            int digit_1 = (last_digit * 2) / 10;

            // Extract digit 2
            int digit_2 = (last_digit * 2) % 10;

            // Add digit 1 and 2 together
            int digits_product = digit_1 + digit_2;

            // Add the product to the uneven_sum
            sum_1 += digits_product;
        }

        else if (counter % 2 == 0)
        {
            // Add the single multiplied digit
            sum_1 += last_digit * 2;
        }

        // Add sum 1 to total
        total += sum_1;

        // Reset sum 1 before next loop
        sum_1 = 0;

        // Increment the counter.
        counter++;
    }

    // Reset checksum because it is 0 now and this loop wouldn't run otherwise
    checksum = cc_number;

    while (checksum != 0)
    {
        // Use the modulus operator (%) to get the last digit of the number.
        int last_digit = checksum % 10;

        // If the counter is even,
        if (counter % 2 == 0)
        {
            // Add the digit to the sum
            sum_2 += last_digit;

            // Add sum 2 to total
            total += sum_2;

            // Reset sum 2 before next loop
            sum_2 = 0;
        }

        // Divide the number by 10 to remove the last digit.
        checksum /= 10;

        // Increment the counter.
        counter++;
    }

    // Determine cc number length and starting digit
    int cc_length = 0;
    int starting_digit = 0;

    while (cc_number > 0)
    {
        // Increment cc length by 1
        cc_length++;

        // If cc number is less than ten,
        if (cc_number < 10)
        {
            // Make this number the starting digit
            starting_digit = cc_number;
        }

        // Divide cc number by 10 and update cc number
        cc_number /= 10;
    }


    // If the last digit is a 0 AND the starting digit is 4 AND the cc length is 13 OR 16
    if ((total % 10 == 0) && (starting_digit == 4) && (cc_length == 13 || cc_length == 16))
    {
        // Print VISA
        printf("VISA\n");
        return 1;
    }

    // Determine cc number length and starting digits
    int cc_length_2 = 0;
    int starting_digits = 0;

    while (cc_number > 10)
    {
        // Increment cc length by 1
        cc_length_2++;

        // If cc number is less than one hundred,
        if (cc_number < 100)
        {
            // Make this number the starting digit
            starting_digits = cc_number;
        }

        // Divide cc number by 10 and update cc number
        cc_number /= 100;
    }

    // Else if the last digit is a 0 AND the starting digit is 51 - 55 AND the cc length is 16
    if ((total % 10 == 0) && (starting_digits >= 51 && starting_digits <= 55) && (cc_length == 16))
    {
        // Print MASTERCARD
        printf("MASTERCARD\n");
        return 1;
    }

    // Else if the last digit is a 0 AND the starting digit is 34 OR 37 AND the cc length is 15
    else if ((total % 10 == 0) && (starting_digits == 34 || starting_digits == 37) && (cc_length == 15))
    {
        // Print AMEX
        printf("AMEX\n");
        return 1;
    }

    // If it's not any of those
    else
    {
        printf("INVALID\n");
    }
}

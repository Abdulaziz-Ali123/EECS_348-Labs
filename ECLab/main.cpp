#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double extrectNumaric(const string &str)
{

    // keep track of result
    double result = 0.0;

    // help to insure the only non numbers are +/- at the begining
    bool isFirst = true;

    // track if number is negative
    bool isNegative = false;

    // insures we do not consider more than one decimal point
    bool decimalNotFound = true;

    // place holder for where a decimal digit will go
    double decimalPlaceHolder = 1.0;

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        // set is first
        if (i != 0)
        {
            isFirst = false;
        }
        // check for negative
        if (isFirst && c == '-')
        {
            isFirst = false;
            isNegative = true;
            continue;
        }

        // check for positive
        if (isFirst && c == '+')
        {
            continue;
        }

        // check for decimal
        if (decimalNotFound && c == '.')
        {
            decimalNotFound = false;
        }
        // check for number
        else if ((c >= '0' && c <= '9'))
        {
            // subtrac
            int curDigit = c - '0';
            if (decimalNotFound)
            {
                // shift decimal to left first then add the current digit
                result = (result * 10) + curDigit;
            }
            else
            {
                // shift the decimal value and add it to result
                decimalPlaceHolder /= 10;
                result += curDigit * decimalPlaceHolder;
            }
        }
        else
        {
            return -999999.99;
        }
    }
    if (isNegative)
    {
        return -result;
    }

    return result;
}

int main()
{
    string input;

    while (true)
    {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END")
        {
            break;
        }

        double number = extrectNumaric(input);

        if (number != -999999.99)
        {
            cout << "The input is : " << fixed << setprecision(4) << number << endl;
        }
        else
        {
            cout << "The input is invalid." << endl;
        }
    }
}
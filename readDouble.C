#include <iostream>
#include <string>
#include <climits>

using namespace std;

double ReadDouble(string prompt, bool allowNegative)
{

    bool isValid = true;
    string input;

    do
    {
        isValid = true;
        int decimalPointPos = 0;
        cout << prompt;
        cin >> input;

        while (cin.fail() == 1)
        {
            cout << "Error! Cannot read input.\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << prompt;
            cin >> input;
        }

        while (allowNegative == false && input[0] == '-')
        {
            cout << "Error! Cannot not input a negative number!\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << prompt;
            cin >> input;
        }

        // The first character can be a number, +, -, or a decimal point
        if (input[0] == '.' || isdigit(input[0]) || input[0] == '+' || input[0] == '-')
        {
            int count = 0;

            for (int i = 0; i < input.length(); i++)
            {

                if (input[i] == '.' || isdigit(input[i]) || input[i] == '+' || input[i] == '-' || input[i] == ',')
                {
                    if (input[i] == '.')
                    {
                        if (count == 1) ////Only one decimal point in the number
                        {
                            cout << "There cannot be more than one decimal point! (Position " << i << ") \n";
                            isValid = false;
                        }
                        else
                        {
                            count++;
                            decimalPointPos = i;
                        }
                    }
                    if (count == 1)
                    {
                        if (input[i] == ',') // No commas after the decimal point
                        {
                            cout << "There cannot be commas after the decimal point! (Position " << i << ") \n";
                            isValid = false;
                        }
                    }
                    if (i != 0 && (input[i] == '+' || input[i] == '-'))
                    {
                        cout << "There can only be +/- signs at the beginning of the number! (Position " << i << ") \n";
                        isValid = false;
                    }
                    if (isdigit(input[i]) == 0 && isalpha(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != '.' && input[i] != ',')
                    {
                        cout << "You can only input numbers! (Position " << i << ") \n";
                        isValid = false;
                    }
                }
            }

            if (count == 0) // no decimal point
            {
                decimalPointPos = input.length();
            }

            // Any commas must be in their proper location (ie, separating hundreds from thousands, from millions, etc)
            int commaCounter = 3;
            count = 0;
            for (int i = decimalPointPos - 1; i >= 0; i--)
            {

                if (input[i] == ',')
                {

                    if (count != commaCounter)
                    {
                        cout << "Commas are not  placed correctly! (Position " << i << ") \n";
                        isValid = false;
                    }
                    else
                    {
                        commaCounter += 4;
                    }
                }
                count++;
            }
        }
        else
        {
            cout << "You can only input numbers (double)! \n";
            isValid = false;
        }
    } while (isValid == false);

    string convert;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ',' || input[i] == '+' || input[i] == '-')
        {
            ;
        }
        else
        {
            convert += input.substr(i, 1);
        }
    }

    double returnValue = atof(convert.c_str());
    return returnValue;
};
//
// Created by Frank Yang on 2023/8/14.
//

#include <iostream>
#include "Fraction.h"
#include "Calculation.cpp"

inline std::string removeSpaceAndLineChange(const std::string &str)
{
    if (!str.size())
        return str;

    std::string temp = "";

    for (int i = 0; i <= str.size()-1; i++)
        if (str[i] != ' ' && str[i] != '\n')
            temp += str[i];

    return temp;
}

inline bool isStringValid(const std::string &str) // ALL STRINGS HERE ARE SIZED
{
    bool lettersExist = false;
    bool numbersExist = false;
    bool otherSymbolsExist = false;

    if (!((str[0] >= 0x41 && str[0] <= 0x5A) ||
          (str[0] >= 0x61 && str[0] <=0x7A) ||
          str[0] >= 0x30 && str[0] <= 0x39 ||
          str[0] == '-' || str[0] == '+' ||
           str[0] == '(' || str[0] == ')' ||
          str[0] == '[' || str[0] == ']'))
        return false;

    if (!((str[str.size()-1] >= 0x41 && str[str.size()-1] <= 0x5A) ||
          (str[str.size()-1] >= 0x61 && str[str.size()-1] <=0x7A) ||
          str[str.size()-1] >= 0x30 && str[str.size()-1] <= 0x39 ||
          str[str.size()-1] == ']' || str[str.size()-1] == ')'))
        return false;

    for (int i=0; i<=str.size()-1; i++)
    {
        if ((str[i] >= 0x41 && str[i] <= 0x5A) || (str[i] >= 0x61 && str[i] <=0x7A))
            lettersExist = true;
        else if (str[i] >= 0x30 && str[i] <= 0x39)
            numbersExist = true;
        else if (str[i] == '(' || str[i] == ')' ||
                 str[i] == '[' || str[i] == ']' ||
                 str[i] == '+' || str[i] == '-' ||
                 str[i] == '*' || str[i] == '/' ||
                 str[i] == '.')
            {}
        else
            otherSymbolsExist = true;
    }

    if (lettersExist && numbersExist)
        return false;
    else if (otherSymbolsExist)
        return false;
    else
        return true;
}

inline std::string parse(const std::string &input)
{
    std::string inputWithoutSpaceAndLineChange = removeSpaceAndLineChange(input);

    if(!inputWithoutSpaceAndLineChange.size())
        return "EMPTY_STRING";

    if (!isStringValid(inputWithoutSpaceAndLineChange))
        return "INVALID_STRING";

    // REMOVE THE '+' ON THE FIRST
    if (inputWithoutSpaceAndLineChange[0] == '+')
    {
        std::string temp = inputWithoutSpaceAndLineChange;
        inputWithoutSpaceAndLineChange.clear();

        for (int i=1; i<=temp.size()-1; i++)
            inputWithoutSpaceAndLineChange += temp[i];

        temp.clear();
    }

    if (inputWithoutSpaceAndLineChange.size() && (
            (inputWithoutSpaceAndLineChange[0] >= 0x41 && inputWithoutSpaceAndLineChange[0] <= 0x5A) ||
            (inputWithoutSpaceAndLineChange[0] >= 0x61 && inputWithoutSpaceAndLineChange[0] <=0x7A) ) ) // All Letters
        return inputWithoutSpaceAndLineChange;

    else // expression
    {
        Fraction result = recognizingExpression(inputWithoutSpaceAndLineChange);
        std::string resultString = result.fractionToString();
        if (resultString.size() >= 3 && resultString[resultString.size() - 2] == '/' && resultString[resultString.size() - 1] == '1')
        {
            resultString.pop_back();
            resultString.pop_back();
        }
        return resultString;
    }
}

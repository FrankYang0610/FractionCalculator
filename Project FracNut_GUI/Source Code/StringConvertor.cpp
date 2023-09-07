// std::string to QString


#include <iostream>
#include <QString>
#include <cmath>

inline std::string removeLineChange(const std::string &str)
{
    if (!str.size())
        return str;

    std::string temp = "";

    for (int i = 0; i <= str.size()-1; i++)
        if (str[i] != '\n')
            temp += str[i];

    return temp;
}

inline QString stringConvert(std::string str)
{
    str = removeLineChange(str);

    if (!str.size())
        return "USER_NOT_INPUT";

    QString _str = "";

    for (int i=0; i<=str.size()-1; i++)
        _str += str[i];

    return _str;
}

inline QString unsignedIntConvert(unsigned int i)
{
    QString _str = "";

    int digits = 0;

    for (int j=i; j; j/=10)
        digits++;

    for (int j=digits; j>=1; j--)
        _str += (char)((unsigned int)(i % (int)pow(10,j)) / (int)pow(10,j-1) + 0x30);

    return _str;
}


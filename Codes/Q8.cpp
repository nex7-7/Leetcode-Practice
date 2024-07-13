#include <iostream>
using namespace std;

int myAtoi(string s)
{
    int num = 0;
    int16_t adder = 0;
    bool signCheck = false;
    bool negative = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (!signCheck && s[i] == 32)
            continue;
        else if (!signCheck && s[i] == 43)
        {
            signCheck = true;
        }
        else if (!signCheck && s[i] == 45)
        {
            signCheck = true;
            negative = true;
        }
        else if (s[i] >= 48 && s[i] <= 57)
        {
            signCheck = true;
            if (negative)
            {
                adder = (-1) * ((int16_t)(s[i] - 48));
            }
            else
            {
                adder = (int16_t)(s[i] - 48);
            }
            if (!negative && ((num > INT32_MAX / 10) ||
                              (num == INT32_MAX / 10 && adder > 7)))
            {
                num = INT32_MAX;
                break;
            }
            else if (negative && ((num < INT32_MIN / 10) ||
                                  (num == INT32_MIN / 10 && adder < -8)))
            {
                num = INT32_MIN;
                break;
            }
            else
                num = num * 10 + adder;
        }
        else
        {
            break;
        }
    }
    return num;
}

int main()
{
    string s = "1337c0d3";
    cout << myAtoi(s);
    return 0;
}
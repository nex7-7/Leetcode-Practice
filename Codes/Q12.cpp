#include <iostream>
using namespace std;

string intToRoman(int num)
{
    string roman = "";
    uint16_t digit;
    string store[4] = {"IVX", "XLC", "CDM", "M"};
    for (int i = 0; i < 4; i++)
    {
        string set;
        digit = num % 10;
        if (digit <= 3)
        {
            set = string(digit, store[i][0]);
        }
        else if (digit <= 5)
        {
            set = string((5 - digit), store[i][0]);
            set += store[i][1];
        }
        else if (digit <= 8)
        {
            set = string((digit - 5), store[i][0]);
            set = store[i][1] + set;
        }
        else if (digit == 9)
        {
            set = store[i][0];
        }
        roman = set + roman;
        if (num != 0)
        {
            num /= 10;
        }
        else
            break;
    }
    return roman;
}

int main()
{
    int test = 9;
    cout << intToRoman(test);
    return 0;
}
#include <iostream>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int num = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'I')
            {
                if (i < s.size() - 1 && s[i + 1] != 'I')
                    num -= 1;
                else
                    num += 1;
            }
            else if (s[i] == 'X')
            {
                if (i < s.size() - 1 && s[i + 1] != 'X' && s[i + 1] != 'V' &&
                    s[i + 1] != 'I')
                    num -= 10;
                else
                    num += 10;
            }
            else if (s[i] == 'C')
            {
                if (i < s.size() - 1 && s[i + 1] != 'C' && s[i + 1] != 'L' &&
                    s[i + 1] != 'X' && s[i + 1] != 'V' && s[i + 1] != 'I')
                    num -= 100;
                else
                    num += 100;
            }
            else if (s[i] == 'V')
                num += 5;
            else if (s[i] == 'L')
                num += 50;
            else if (s[i] == 'D')
                num += 500;
            else if (s[i] == 'M')
                num += 1000;
        }
        return num;
    }
};
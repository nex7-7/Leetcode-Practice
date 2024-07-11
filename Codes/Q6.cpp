#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string rows[numRows];
        int rem;
        for (int i = 0; i < s.size(); i++)
        {
            rem = i % (2 * (numRows - 1));
            if (rem > (numRows - 1))
            {
                rem = rem - (2 * (rem - (numRows - 1)));
            }
            rows[rem] += s[i];
        }
        for (int i = 1; i < numRows; i++)
        {
            rows[0] += rows[i];
        }
        return rows[0];
    }
};
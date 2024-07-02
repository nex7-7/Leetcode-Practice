#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans;
        for (int i = 0; i <= rowIndex; i++)
        {
            if (i == 0 || i == rowIndex)
            {
                ans.push_back(1);
            }
            else if (i <= rowIndex / 2)
            {
                ans.push_back(choice(rowIndex, i));
            }
            else
            {
                ans.push_back(ans[rowIndex - i]);
            }
        }
        return ans;
    }

private:
    uint64_t lastChoice = 0;
    int choice(uint8_t n, uint8_t r)
    {

        uint64_t ans;

        if (this->lastChoice == 0)
        {
            ans = n;
        }
        else
        {
            ans = (this->lastChoice * (n - r + 1)) / r;
        }
        this->lastChoice = ans;
        return ans;
    }
};
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min = prices[0];
        int max = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < min)
            {
                min = prices[i];
                max = 0;
            }
            if (prices[i] > max)
            {
                max = prices[i];
            }
            if (max - min > maxProfit)
            {
                maxProfit = max - min;
            }
        }
        return maxProfit;
    }
};
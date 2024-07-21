#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    uint16_t minDiff = 0;
    int diff;
    int total;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k)
        {
            total = nums[i] + nums[j] + nums[k];
            diff = target - total;

            if (minDiff == 0)
            {
                minDiff = abs(diff);
                ans = total;
            }

            if (abs(diff) < minDiff)
            {
                minDiff = abs(diff);
                ans = total;
            }

            if (diff < 0)
            {
                k--;
            }
            else if (diff > 0)
            {
                j++;
            }
            else
            {
                j++;
                return total;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> test = {-1, 2, 1, -4};
    cout << threeSumClosest(test, 1);
    return 0;
}
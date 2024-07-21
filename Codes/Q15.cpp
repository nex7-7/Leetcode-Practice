#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

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
            int total = nums[i] + nums[j] + nums[k];

            if (total > 0)
            {
                k--;
            }
            else if (total < 0)
            {
                j++;
            }
            else
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;

                while (nums[j] == nums[j - 1] && j < k)
                {
                    j++;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> test = {-1, 0, 1, 2, 1, 4};
    // vector<int> test = {-1, 0, 1, 2, 1, 4};
    // vector<int> test = {0, 0, 0};
    cout << threeSum(test)[0][0] << endl;
    return 0;
}
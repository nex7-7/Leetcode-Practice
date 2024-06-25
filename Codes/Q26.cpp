#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int t = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[t]) {
                swap(nums[i], nums[t + 1]);
                t++;
            }
        }
        return t + 1;
    }
};
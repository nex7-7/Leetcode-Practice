#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int space = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if(nums[i] == val){
                space ++;
                continue;
            }
            if(space > 0){
                nums[(i - space)] = nums[i];
            }
        }
        return (size - space);
    }
};
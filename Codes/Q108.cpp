#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

TreeNode *sortedArrayToBST(vector<int> &nums, int p, int q)
{
    if (p > q)
        return NULL;
    int mid = (p + q / 2);
    TreeNode *root = new TreeNode(nums[mid]);
    
    root->left = sortedArrayToBST(nums, p, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, q);
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    TreeNode *root = sortedArrayToBST(nums, 0, nums.size() - 1);
    return root;
}

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode *root = sortedArrayToBST(nums);
}

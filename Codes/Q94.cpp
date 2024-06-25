#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
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

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> sol;
        if (root == NULL)
            return sol;
        vector<int> left = inorderTraversal(root->left);
        sol.insert(sol.end(), left.begin(), left.end());
        sol.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);
        sol.insert(sol.end(), right.begin(), right.end());
        return sol;
    }
};
#include <iostream>
#include <stack>
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

int check(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int depthLeft = check(root->left) + 1;
    int depthRight = check(root->right) + 1;
    if (depthLeft > depthRight)
        return depthLeft;
    else
        return depthRight;
}

bool isBalanced(TreeNode *root)
{
    if (root == NULL)
        return true;
    int depthLeft = check(root->left);
    int depthRight = check(root->right);
    int diff = depthLeft - depthRight;
    if (diff > 1 || diff < -1)
        return false;
    else
        return isBalanced(root -> left) && isBalanced(root -> right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->left->left->left = new TreeNode(8);
    cout << isBalanced(root) << endl;
}
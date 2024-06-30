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

struct element
{
    TreeNode *t;
    int sum;
};

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == NULL)
    {
        return false;
    }

    TreeNode *curr = root;
    int currSum = 0;
    stack<element> s;
    element store;

    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            currSum += curr->val;
            if (currSum == targetSum && curr->left == NULL &&
                curr->right == NULL)
                return true;
            store.t = curr;
            store.sum = currSum;
            s.push(store);
            curr = curr->left;
        }

        if (s.empty())
            break;
        store = s.top();
        curr = store.t;
        currSum = store.sum;
        s.pop();
        curr = curr->right;
    }
    return false;
}

int main()
{
    // Create the tree
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    // Call the hasPathSum function
    int targetSum = 22;
    bool result = hasPathSum(root, targetSum);

    // Print the result
    cout << "Path with sum " << targetSum << " exists: " << (result ? "true" : "false") << endl;

    // Clean up the memory
    delete root->right->right->right;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->left->right;
    delete root->left->left->left;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
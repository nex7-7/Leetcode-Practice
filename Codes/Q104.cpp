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
    TreeNode *node;
    int height;
};

int maxDepth(TreeNode *root)
{
    stack<element> s;
    TreeNode *curr;
    element store;
    curr = root;
    int maxHeight = 0;
    int currHeight = 0;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            ++currHeight;
            store.node = curr;
            store.height = currHeight;
            s.push(store);
            curr = curr->left;
        }
        if (currHeight > maxHeight)
            maxHeight = currHeight;

        store = s.top();
        curr = store.node;
        currHeight = store.height;
        curr = curr->right;
        s.pop();
    }
    return maxHeight;
}
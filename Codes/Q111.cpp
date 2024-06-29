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

int minDepth(TreeNode *root)
{
    stack<element> s;
    TreeNode *curr;
    element store;
    curr = root;
    int minHeight = 0;
    int currHeight = 0;
    bool first = true;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            ++currHeight;

            if (!first && (currHeight >= minHeight))
                break;

            if (first && curr->left == NULL && curr->right == NULL)
            {
                minHeight = currHeight;
                first = false;
                break;
            }

            if (!first && curr->left == NULL && curr->right == NULL && currHeight < minHeight)
            {
                minHeight = currHeight;
                break;
            }

            store.node = curr;
            store.height = currHeight;
            s.push(store);
            curr = curr->left;
        }

        if (s.empty())
            break;
        store = s.top();
        curr = store.node;
        currHeight = store.height;
        curr = curr->right;
        s.pop();
    }
    return minHeight;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << minDepth(root) << endl;
}
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

bool isSymmetric(TreeNode *root)
{
    TreeNode *p = root->left;
    TreeNode *q = root->right;

    if (p == NULL ^ q == NULL)
        return false;

    stack<TreeNode *> sp;
    stack<TreeNode *> sq;

    while ((p != NULL || q != NULL) || (!sp.empty() && !sq.empty()))
    {

        while (p != NULL && q != NULL)
        {
            if (p->val == q->val)
            {
                sp.push(p);
                sq.push(q);
                p = p->left;
                q = q->right;
            }
            else
                return false;
        }

        if (p == NULL && q == NULL && (!sp.empty() && !sq.empty()))
        {
            p = sp.top();
            q = sq.top();
            sp.pop();
            sq.pop();
            p = p->right;
            q = q->left;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    TreeNode llc = TreeNode(4);
    TreeNode lrc = TreeNode(5);
    TreeNode rrc = TreeNode(4);
    TreeNode lc = TreeNode(3, &llc, &lrc);
    TreeNode rc = TreeNode(3, nullptr, &rrc);
    TreeNode t = TreeNode(2, &lc, &rc);
    isSymmetric(&t);
}
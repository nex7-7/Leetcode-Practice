#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    unsigned int carry = 0;
    int sum = 0;
    ListNode *ans = new ListNode();
    ListNode *head = ans;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {

        head->next = new ListNode();
        head = head->next;

        sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sum / 10;
        sum %= 10;

        head->val = sum;

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    };

    head = ans->next;
    delete ans;
    return head;
}

int main()
{
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode *ans = addTwoNumbers(l1, l2);
    return 0;
}
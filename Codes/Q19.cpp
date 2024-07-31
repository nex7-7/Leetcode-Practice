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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *curr = head;
    ListNode *prev = nullptr;
    ListNode *target = head;
    int count = 0;
    while (curr != nullptr)
    {
        count++;
        if ((count - n) > 0)
        {
            prev = target;
            target = target->next;
        }
        curr = curr->next;
    }

    if (prev == nullptr)
    {
        head = target->next;
    }
    else
    {
        prev->next = target->next;
    }

    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);

    removeNthFromEnd(head, 1);
    return 0;
}
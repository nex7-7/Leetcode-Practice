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

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *ptr1 = head;
        ListNode *prev = head;
        if (head == nullptr)
        {
            return head;
        }
        bool flag = false;
        while (ptr1 != nullptr && ptr1->next != nullptr)
        {
            ListNode *ptr2 = ptr1->next;
            ListNode *ptr3 = ptr2 == nullptr ? nullptr : ptr2->next;
            ListNode *ptr4 = ptr3 == nullptr ? nullptr : ptr3->next;
            if (!flag)
            {
                head = ptr2;
            }
            prev = swap(prev, ptr1, ptr2, ptr3, ptr4);
            ptr1 = prev->next;
            flag = true;
        }
        return head;
    }

    ListNode *swap(ListNode *prev, ListNode *node1, ListNode *node2, ListNode *node3,
                   ListNode *node4)
    {
        if (node2 == nullptr && node3 == nullptr && node4 == nullptr)
        {
            return node1;
        }
        else if (node3 == nullptr && node4 == nullptr)
        {
            prev->next = node2;
            node2->next = node1;
            node1->next = nullptr;
            return node1;
        }
        else if (node4 == nullptr)
        {
            prev->next = node2;
            node2->next = node1;
            node1->next = node3;
            return node3;
        }
        else
        {
            ListNode *aux = new ListNode();
            prev->next = node2;
            node2->next = node1;
            node1->next = node4;
            aux = node4->next;
            node4->next = node3;
            node3->next = aux;
            return node3;
        }
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    ListNode *ptr = head;
    for (int i = 2; i <= 8; i++)
    {
        ptr->next = new ListNode(i);
        ptr = ptr->next;
    }
    ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
    head = s.swapPairs(head);
    ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
    return 0;
}
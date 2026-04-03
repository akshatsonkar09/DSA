#include <iostream>
#include <bits/stdc++.h>

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *ptr1 = l1, *ptr2 = l2;
        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;

        while (ptr1 && ptr2)
        {
            if (ptr1->val + ptr2->val + carry >= 10)
            {
                ListNode *newNode = new ListNode(ptr1->val + ptr2->val - 10 + carry);
                carry = 1;
                temp->next = newNode;
                temp = newNode;
            }
            else
            {
                ListNode *newNode = new ListNode(ptr1->val + ptr2->val + carry);
                carry = 0;
                temp->next = newNode;
                temp = newNode;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        while (ptr1)
        {
            ListNode *newNode = new ListNode(ptr1->val + carry);
            carry = 0;
            if (newNode->val >= 10) carry = 1;
            temp->next = newNode;
            temp = newNode;
            ptr1 = ptr1->next;
        }
        while (ptr2)
        {
            ListNode *newNode = new ListNode(ptr2->val + carry);
            carry = 0;
            if (newNode->val >= 10) carry = 1;
            temp->next = newNode;
            temp = newNode;
            ptr2 = ptr2->next;
        }
        return dummyNode->next;
    }
};
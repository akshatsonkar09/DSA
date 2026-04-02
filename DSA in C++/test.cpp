
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
    ListNode *findmiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *merge(ListNode *ptr1, ListNode *ptr2)
    {
        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;
        while (ptr1 && ptr2)
        {
            if (ptr1->val < ptr2->val)
            {
                temp->next = ptr1;
                temp = ptr1;
                ptr1 = ptr1->next;
            }

            else
            {
                temp->next = ptr2;
                temp = ptr2;
                ptr2 = ptr2->next;
            }
        }

        while (ptr1)
        {
            temp->next = ptr1;
            temp = ptr1;
            ptr1 = ptr1->next;
        }
        while (ptr2)
        {
            temp->next = ptr2;
            temp = ptr2;
            ptr2 = ptr2->next;
        }
        return dummyNode->next;
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *middle = findmiddle(head);
        ListNode *lefthead = head;
        ListNode *righthead = middle->next;
        middle->next = nullptr;

        lefthead = sortList(lefthead);
        righthead = sortList(righthead);
        return merge(lefthead, righthead);
    }
};
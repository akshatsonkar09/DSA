#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*ALL THE CODES ARE WRITTEN SUCH THAT INDEX IS WITHIN THE LL*/

class Node // You can use struct Node as well but c++ gives us better ways like class
{
public:
    // data ko define karte hai and then uska ek struct form ka deconstructor bana dete hai
    int data;
    Node *next;

    // this is for normal nodes
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // this is for last nodes
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int Length_of_Linked_List(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int checkIfPresent(Node *head, int val)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void printll(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *deleteHead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == NULL /*Empty LL*/)
        return NULL;
    if (head->next /*Singly LL*/ == NULL)
    {
        delete head;
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next /*because we have to stop at the second last step*/ != NULL)
    {
        temp = temp->next; // This will take to the last node
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// This is Strivers
//  Node *deleteatIndex(Node *head, int k)
//  {
//      if (head == NULL)//for empty
//          return head;
//      if (k == 1)     //for head
//      { // this is done to make the value at second index the new head otherwise we would lose head
//          // Node *temp = head;
//          // head = head->next;
//          // delete temp;
//          // return head;
//          return deleteHead(head);
//      }
//      int cnt = 1;    //Why 1 and not 0(Reason because we have temp = head)
//      Node *temp = head;
//      Node *prev = NULL;
//      while (temp != NULL)
//      {
//          cnt++;
//          if (cnt == k)
//          {
//              prev->next = prev->next->next;
//              delete temp;
//              break;
//          }
//          prev = temp; // left value right par jaati hai isliye prev phir null se index 1 then due to next line temp at index 2 and again prev = temp se prev at index 2 and temp at index 3
//          temp = temp->next;
//      }
//      return head;
//  }

// GPT CODE
Node *deleteatindex(Node *head, int k)
{
    Node *temp = head;
    Node *prev = nullptr;
    if (head == NULL)
        return head;
    if (k == 1)
        return deleteHead(head);

    int cnt = 1;

    while (temp != NULL && cnt < k)
    {
        prev = temp;
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL)
        return head; // Critical failsafe

    prev->next = temp->next;
    temp->next = nullptr;
    delete temp;
    return head;
}

Node *deleteatvalue(Node *head, int val)
{
    if (head == NULL)
        return head;
    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *insertatHead(Node *head, int val)
{
    /*
    Node* temp = new Node(val,head);
    head = temp;
    return head;
    //OR
    Node* temp = new Node(val,head);
    return temp;
    //OR
    */
    return new Node(val, head);
}

Node *insertatLast(Node *head, int val)
{
    if (head == NULL)
        return new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node *insertatindex(Node *head, int k, int val)
{
    if (head == NULL)
    {
        if (k == 1)
            return new Node(val);
        else
            return NULL;
    }
    if (k == 1)
    {
        // Node* temp = new Node(val);
        // return temp;
        // OR
        return new Node(val, head);
    }
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        if (cnt == k - 1)
        {
            Node *newNode = new Node(val, temp->next);
            temp->next = newNode;
            // return head;
            break;
        }
        temp = temp->next;
        cnt++;
    }
    return head;
}

Node *insertbeforevalue(Node *head, int val, int insertval)
{
    if (head == NULL)
        return NULL;
    if (head->data == val)
        return new Node(insertval, head);
    Node *temp = head;
    bool found = false;
    // while (temp != NULL)
    while (temp->next != NULL)
    {
        if (val == temp->next->data)
        {
            Node *newNode = new Node(insertval, temp->next);
            temp->next = newNode;
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (found == false)
        return head;
    return head;
}

Node *ReverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = head;
    Node *front = head->next;
    Node *prev = nullptr;

    while (temp != NULL)
    {
        front = temp->next;     
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
//Temp aur prev ko assign karo aur loop me temp bolega front ko aage aane ke liye fir temp ne prev par apni  arrow tail daal di aur prev temp ke paas aa kar mar gaya aur temp chala gaya front ke paas

// Tortoise & hare Method
Node *MidofLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool FloydLoopDetection(Node *head)
{
    if (head == NULL)
        return false;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}
// Floyd as a rabbit monster with F on his head first ask if you have h taken head = NULL condition if not he screams in anime style to go away/false.Then He asks you to take two pointers/two man race. Then he tells you to race him until he drops ie your while condition. You two start racing and he drops when you both collide

bool isPalindrome(Node* head) {
        if(head == NULL || head->next == NULL) return true;

        //Reaching mid point(m1)
        Node *slow = head;
        Node *fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //Reversing the half
        Node *prev = nullptr;
        Node *temp = slow->next;
        Node* front;
        while(temp) {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        slow->next = nullptr;

        //Making heads and checking
        Node* newHead = prev;   //prev is pointing towards last node 
        Node *first = head;
        Node *second = newHead;

        while(second) {
            if(first->data != second->data) return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }

int main()
{
    vector<int> Arr = {2, 5, 8, 7};
    Node *y = new Node(Arr[0], nullptr);
    cout << y->data << endl; // IMPORTANT -> There are various ways to write it so see it carefully
    cout << endl;

    vector<int> arr = {2, 5, 8, 7};
    Node *head = convertArr2LL(arr);
    cout << head->data << endl;
    cout << endl;

    printll(head);
    head = deleteHead(head);
    printll(head);
    cout << endl;

    arr = {2, 5, 8, 7};
    head = convertArr2LL(arr);
    printll(head);
    head = deleteTail(head);
    printll(head);
    cout << endl;

    arr = {2, 5, 8, 7};
    head = convertArr2LL(arr);
    printll(head);
    head = deleteatindex(head, 2);
    printll(head);
    cout << endl;

    arr = {2, 5, 8, 7};
    head = convertArr2LL(arr);
    printll(head);
    head = deleteatvalue(head, 8);
    printll(head);
    cout << endl;

    arr = {2, 5, 8, 7};
    head = convertArr2LL(arr);
    printll(head);
    head = insertatHead(head, 1);
    printll(head);
    cout << endl;

    arr = {2, 5, 8, 7};
    head = convertArr2LL(arr);
    printll(head);
    head = insertatLast(head, 10);
    printll(head);
    cout << endl;

    arr = {2, 5, 8, 7};
    head = convertArr2LL(arr);
    printll(head);
    head = insertatindex(head, 3, 9);
    printll(head);
    cout << endl;

    arr = {2, 5, 8, 7};
    head = convertArr2LL(arr);
    printll(head);
    head = insertbeforevalue(head, 3, 9);
    printll(head);
    cout << endl;

    arr = {2, 5, 8, 7};
    head = convertArr2LL(arr);
    printll(head);
    head = MidofLL(head);
    cout << head->data << endl;

    return 0;
}
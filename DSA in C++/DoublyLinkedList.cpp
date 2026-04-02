#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*ALL THE CODES ARE WRITTEN SUCH THAT INDEX IS WITHIN THE LL*/
class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convertArr2DLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
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

Node *deletionathead(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr; // Jo initial head tha uska back toh
    delete temp;
    return head;
}

Node *deletionattail(Node *head)
{
    if (head == NULL)
        return head;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *temp = head;
    Node *prev = nullptr;   //prev is going to be new tail

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    prev = temp->back;
    prev->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}


Node* deletionatindex(Node* head, int k) {
        if(head == NULL) return head;
        int cnt = 0;
        Node* temp = head;
        while(temp != NULL) {
            cnt++;
            if(cnt == k) break;
            temp = temp->next;
        }
        Node* prev = temp->back;
        Node* front = temp->next;

        if(prev==NULL && front == NULL) return NULL;    //Singly DLL
        else if(prev == NULL) return deletionathead(head);
        else if(front == NULL) return deletionattail(head);

        prev->next = front;
        front->back = prev;
        temp->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return head;
    }
//Strivers Code is above

/* My code is below
Node *deletionatindex(Node *head, int k) {
    if(head == NULL || k<=0) return head;

    Node* temp = head;
    
    if(k==1) {
        head = head->next;

        if(head!=NULL)
        head->back = nullptr;

        temp->next = nullptr;
        delete temp;
        return head;
    }

    int cnt = 1;

    while (temp != NULL && cnt<k)
    {
        //prev = temp;     //har baar yeh karne ki zarurat hi nahi hai jab pohoch jaao temp par tab define kar lena
        temp = temp->next;
        //front = temp->next;      //har baar yeh karne ki zarurat hi nahi hai jab pohoch jaao temp par tab define kar lena
        cnt++;
    }

     Node* prev = temp->back;
     Node* front = temp->next;

        if (front != NULL) front->back = prev;

    prev->next = front;

    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;

    return head;
}
*/


Node* deletionatvalue(Node* head, int val) {
    if(head == NULL) return head;
    Node* temp = head;
    while(temp != NULL) {
        if(val == temp->data) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    
    if(prev==NULL && front == NULL) return NULL;    //Singly DLL
    else if(prev == NULL) return deletionathead(head);
    else if(front == NULL) return deletionattail(head);
    
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

Node* deletenode(Node* head,Node* temp) {  //Assumption node given !=head
    Node* prev = temp->back;
    Node* front = temp->next;

    if (front == NULL)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return head;
    }
    
    prev->next = front;
    front->back = prev;

    temp->back = temp->back = nullptr;
    delete temp;
    return head;
}

Node* InsertionBeforeHead(Node* head, int val) {
    if(head == NULL) return head;

    Node* newNode = new Node(val);
    newNode->next = head;
    head->back = newNode;
    // head = newNode; This is correct 
    // return head;
    // newNode = head   This is wrong
    return newNode;
}


Node* InsertionAfterHead(Node* head, int val) {
    if(head == NULL) return head;

    Node* newNode = new Node(val,head->next,head);
    Node* front = head->next;
    if(front!=NULL)
    front->back = newNode;
    head->next = newNode;
    return head;
}

Node* InsertionBeforeTail(Node* head, int val) {
    if(head==NULL) return head;
    if(head->next ==NULL) return InsertionBeforeHead(head,val);
    Node* temp = head;
    Node* prev;
    while (temp->next != NULL)
    {
        temp= temp->next;
    }
    prev = temp->back;
    Node* newNode = new Node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

Node* InsertionAfterTail(Node* head, int val) {
    //LEFT
}
Node* InsertionAfterIndex(Node* head, int val) {
    //LEFT
}
Node* InsertionAfterValue(Node* head, int val) {
    //LEFT
}

Node* InsertionBeforeIndex (Node* head, int k, int val) {
    if(head==NULL) return head;
    if(k==1) return InsertionBeforeHead(head,val);
    
    Node* temp = head;
    Node* prev;
    int cnt = 0;

    while (temp!=NULL)
    {
        cnt++;
        if(cnt==k) break;
        temp= temp->next;
    }
    prev= temp->back;
    Node* newNode = new Node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

Node* InsertionBeforeValue (Node* head, int val) {
    if(head==NULL) return head;
    if(head->data == val) return InsertionBeforeHead(head,val);
    Node* temp = head;
    Node* prev;

    while (temp!=NULL)
    {
        if(temp->data==val) break;
        temp= temp->next;
    }
    prev= temp->back;
    Node* newNode = new Node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

Node* InsertionBeforeNode(Node* head, Node* node, int val) {
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
    return head;
}

Node* ReverseDLL (Node* head) {
    if(head==NULL|| head->next == NULL) return head;
    Node* prev = NULL;
    Node* current = head;
    while (current!=NULL)
    {
        /*Same as swapping numbers*/
        prev = current->back;
        current->back = current->next;
        current->next = prev;
    }
    return prev->back;
}

Node* deletealloccurance(Node *head, int key) {
        Node *temp = head;

        while (temp)
        {
            if (temp->data == key)
            {
                if(temp == head) head = head->next;
                Node *nextNode = temp->next;
                Node *prevNode = temp->back;

                if(nextNode) nextNode->back = prevNode;
                if(prevNode) prevNode->next = nextNode;
                free(temp);
                temp = nextNode;
            }
            else temp = temp->next;
            
        }   
}

int main()
{

    vector<int> arr = {2, 5, 8, 7};
    Node *head = convertArr2DLL(arr);
    cout << head->data << endl;
    printll(head);
    cout << endl;

    arr = {2, 5, 8, 7};
    head = convertArr2DLL(arr);
    printll(head);
    head = deletionathead(head);
    printll(head);
    cout << endl;
    
    arr = {2, 5, 8, 7};
    head = convertArr2DLL(arr);
    printll(head);
    head = deletionattail(head);
    printll(head);
    cout << endl;
    
    arr = {2, 5, 8, 7};
    head = convertArr2DLL(arr);
    printll(head);
    head = deletionatindex(head,4);
    printll(head);
    cout << endl;

    arr = {2, 5, 8, 7};
    head = convertArr2DLL(arr);
    printll(head);
    head = deletionatvalue(head,8);
    printll(head);
    cout << endl;
    
    arr = {2, 5, 8, 7};
    head = convertArr2DLL(arr);
    printll(head);
    head = deletenode(head,head->next);
    printll(head);
    cout << endl;

    arr = {2, 5, 8, 7};
    head = convertArr2DLL(arr);
    printll(head);
    head = InsertionBeforeHead(head,1);
    printll(head);
    cout << endl; 

    arr = {2, 5, 8, 7};
    head = convertArr2DLL(arr);
    printll(head);
    head = InsertionAfterHead(head,3);
    printll(head);
    cout << endl;
    
    arr = {2, 5, 8, 7};
    head = convertArr2DLL(arr);
    printll(head);
    head = InsertionBeforeTail(head,1);
    printll(head);
    cout << endl;    

    // arr = {2, 5, 8, 7};
    // head = convertArr2DLL(arr);
    // printll(head);
    // head = InsertionAfterTail(head,10);
    // printll(head);
    // cout << endl;  

    arr = {2, 5, 8, 7};
    head = convertArr2DLL(arr);
    printll(head);
    head = InsertionBeforeIndex(head,2,10);
    printll(head);
    cout << endl;    

    // arr = {2, 5, 8, 7};
    // head = convertArr2DLL(arr);
    // printll(head);
    // head = InsertionAfterIndex(head,2,10);
    // printll(head);
    // cout << endl;  

    arr = {2, 5, 8, 7};
    head = convertArr2DLL(arr);
    printll(head);
    head = InsertionBeforeValue(head,8);
    printll(head);
    cout << endl; 

    // arr = {2, 5, 8, 7};
    // head = convertArr2DLL(arr);
    // printll(head);
    // head = InsertionAfterValue(head,8);
    // printll(head);
    // cout << endl;  

    arr = {2, 5, 8, 7};
    head = convertArr2DLL(arr);
    printll(head);
    head = InsertionBeforeNode(head,head->next,6);
    printll(head);
    cout << endl;

    return 0;
}
#include <iostream>
#include <bits/stdc++.h>

// Stack is LIFO and Queue is FIFO
using namespace std;

// Stack using arrays
class StImpl    //All functions in this are of O(1) time complexity
{

public:
    int top = -1;
    int st[10];

    void push(int val)
    {
        if (top >= 9)
            return;
        top++;         // new slot par jayega
        st[top] = val; // ab woh slot fill ho jayega
    }
    int Top()
    {
        if (top == -1)
            return -1;
        return st[top];
    }

    void pop()
    {
        if (top == -1)
            return;
        top--;
    }

    int size()
    {
        return top + 1;
    }
};

// Queue using array
class QueueUsingArray
{
    int size = 10;
    int q[10];
    int currsize = 0;
    int start = -1;
    int end = -1;

public:
    void push(int val)
    {
        if (currsize == size)
            return;
        if (currsize == 0)
            start = end = 0;
        else
            end = (end + 1) % size;     //For wrapping around the array
        q[end] = val;
        currsize++;
    }

    void pop()
    {
        if (currsize == 0)
            return;
        int element = q[start];
        if (currsize == 1)
            start = end = -1;
        else
            start = (start + 1) % size;
        currsize--;
        return;
    }

    int Top()
    {
        if (currsize == -1)
            return -1;
        return q[start];
    }

    int size()
    {
        return currsize;
    }
};

class StackusingLinkedList
{
    class Node {
        public: 
        Node* next;
        int data;
        Node(Node* next1, int data1) {
            next = next1;
            data = data1;
        }
    };
    public:
    Node* top = NULL;
    int size = 0;

        void push(int val) {
            Node* temp = new Node(top,val);
            top = temp; 
            size++;
        }  

        void pop() {
            if(top == NULL) return;
            Node* temp = top;
            top = top->next;
            temp->next = nullptr;
            delete temp;
            size--;
        }
        int Top() {
            if(top == NULL) return -1;
             return top->data;
        }
        int Size() {
            return size;
        }
};

class QueueUsingLinkedList {
    public:
    class Node {
        public: 
        Node* next;
        int data;
        Node(Node* next1, int data1) {
            next = next1;
            data = data1;
        }
    };

    int size = 0;
    Node* start = nullptr;
    Node* end = nullptr;

    void push(int val) {//Ignore this for now
        if(start == NULL) {
            Node* temp = new Node(nullptr,val);
            start = end = temp;
            size++;
            return;
        }
        Node* temp = new Node(nullptr,val);
        end->next = temp;
        end=temp;
        size++;
    } 
    void pop() {
        if(start == NULL) return;
        Node* temp = start;
        start = start->next;
        delete temp;
        size--;

        if(start == NULL) end = NULL;
    }
    int top() {
        if(start==NULL) return -1;
        return start->data;
    }
    int Size() {
        return size;
    }
};

class StackUsingQueue /*Always keep the stack top at the front of the queue*/ 
{
    queue <int> q;
    public:

    void push(int val) /*push into queue then rotate it so that now the pushed element is in front of the queue and on popping the front will go out just like it should have happened in stack*/ {
        int size = q.size();
        q.push(val);
        for (int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
            /* For 2,3,4,5 and pushing 1 in front
            we push 1 we get 2,3,4,5,1 then we push the top part which is 2 and pop it from the front making it 3,4,5,1,2*/
        }
    }

    void pop() {
        int n = q.front();
        q.pop();
    }

    int top() {
        return q.front();
    }
    bool isEmpty() {
        return q.empty();
    }
};

class QueueusingStack {
    stack <int> st1, st2;
    //Approach 1 Expensive Push but Cheap Pop
    void push1(int val) {
        while(st1.size())   //while(!st1.empty()) also true
        {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(val);
        
        while(st2.size())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop1 () {
        if(st1.empty()) return -1;
        int front = st1.top();
        st1.pop();
        return front;
    }
    
    int Top1() {
       return st1.top();
    }
    //Approach 2 Cheap Push but Expensive Pop
    void push2 (int val) {

    }
    
    void pop2() {
        if(st2.empty()) st2.pop();
        else while (st1.size())
        {
            st2.push(st1.top());
            st1.pop();
        }
        st2.pop();
    }

    int Top2() {
        if(st2.empty()) st2.top();
        else while (st1.size())
        {
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }
};



int main()
{
    // Stack using array
    StImpl s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.Top() << endl;
    s.pop();
    cout << s.size() << endl;

    // Queue using array
    QueueUsingArray qa;
    qa.push(1);
    qa.push(2);
    qa.push(3);
    cout << qa.Top() << endl;
    qa.pop();

    // Stack using linked list
    StackusingLinkedList sll;
    sll.push(100);
    sll.push(200);
    cout << sll.Top() << endl;
    sll.pop();
    cout << sll.Size() << endl;

    // Queue using linked list
    QueueUsingLinkedList qll;
    qll.push(5);
    qll.push(6);
    qll.push(7);
    cout << qll.top() << endl;
    qll.pop();
    cout << qll.Size() << endl;

    // Stack using queue
    StackUsingQueue sq;
    sq.push(11);
    sq.push(22);
    sq.push(33);
    sq.pop();   // removes top element

    // Queue using stack
    QueueusingStack qs;
    // Only accessible methods are used indirectly
    // (methods are private by default in class)

    return 0;
}
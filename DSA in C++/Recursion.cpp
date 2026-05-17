#include <bits/stdc++.h>
using namespace std;

//VVV IMP Concept is ki bina loop lagaye agar top element save ho jaye toh mera kaam ho jayega isliye recusrion istemal kiya aur usme top ki value hold karwa di

void insertAtBottom(stack<int> &st, int val) {
    if (st.empty()) {
        st.push(val);
        return;
    }

    int topVal = st.top();
    st.pop();

    insertAtBottom(st, val);
    st.push(topVal);
}

// Function to reverse the stack
void reverseStack(stack<int> &st) {
    // Base case: If stack is empty, return
    /*$$*/if (st.empty()) return;

    // Pop the top element
    int topVal = st.top();
    st.pop();

    // Recursively reverse the remaining stack
    reverseStack(st);   /*$$*/ //itna part bas itna kehta hai ki jab tak stack empty nahi ho rahi hai tab tak nikaalte raho

    // Insert the popped element at the bottom
    insertAtBottom(st, topVal);
}


void sortinsert(stack<int>& s, int temp) {
    // Base case: if the stack is empty or temp is larger than the top element
    if (s.empty() || s.top() <= temp) {
        s.push(temp);
        return;
    }
    
    // Otherwise, pop the top element and recursively insert
    int val = s.top();
    s.pop();
    sortinsert(s, temp);
    
    // Push the popped element back
    s.push(val);
}

// Function to sort the stack
void sortStack(stack<int>& s) {
    if (!s.empty()) {
        int temp = s.top();
        s.pop();
        
        sortStack(s);       // ab second top element aayega isme aur phir third and so on
        
        sortinsert(s, temp);
    }
}


int main() {
    // Create a sample stack
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);

    // Reverse the stack
    reverseStack(st);

    // Print the reversed stack
    cout << "Reversed Stack: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
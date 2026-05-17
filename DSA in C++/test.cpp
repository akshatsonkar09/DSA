#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void sortinsert(stack<int> st, int temp)
{
    if (st.empty() || st.top() < temp)
    {
        st.push(temp);
        return;
    }

    int val = st.top();
    st.pop();

    sortinsert(st, temp);

    st.push(val);
}

void sortstack(stack<int> st)
{
    if (st.empty())
        return;

    int temp = st.top();
    st.pop();

    sortstack(st); // ab second top element aayega isme aur phir third and so on

    sortinsert(st, temp);
}
int main()
{

    return 0;
}
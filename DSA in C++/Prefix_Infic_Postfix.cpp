#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//   *+pq-mn{PREFIX}    (p+q)*(m-n){INFIX}     pq+mn-*{POSTFIX}

int priority(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return -1;
}


/*Infix to prefix is simple
1) reverse the string
2) swap the brackets
3) apply the infix to postfix on reversed string
3A) handle the power else case separately
3B) instead of <= it will be <
4) reverse the ans and return*/
string Infix_to_Postfix(string s)
{
    int i = 0, n = s.length();
    string ans = "";
    stack<char> st;
    while (i < n)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')) // This is important thing which you didnt know you can do
        // VVV IMP  instead of ascii range we can use inbuilt if(isalnum(s[i]))
        {
            ans += s[i];
        }

        else if (s[i] == '(')
            st.push(s[i]);

        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                char ch = st.top();
                st.pop();
                ans += ch;
            }
            st.pop(); // for popping (
        }

        else
        {
            while (!st.empty() && priority(s[i]) <= priority(st.top())) // This is saying that until priority
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

string Infix_to_Prefix(string s)
{
    reverse(s.begin(), s.end());
    
    
    stack<char> st;
    int i = 0, n = s.length();
    string ans = "";

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    while (i < n)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
        }

        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            if (s[i] == '^')
            {
                while (!st.empty() && priority(s[i]) <= priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }

            else
            {
                while (!st.empty() && priority(s[i]) < priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    
    return ans;
}

string Postfix_to_Infix (string s) {
    int i = 0, n = s.length();
    stack <string> st;

    while (i<n)
    {
        if(isalnum(s[i])) st.push(string(1,s[i]));
        else {
            string t1 = st.top();
            st.pop();

            string t2 = st.top();
            st.pop();

            string cont = "(" + t2 + string(1,s[i]) + t1 + ")";
            st.push(cont);
        }
        i++;
    }
    return st.top();
}

int main()
{
    string infix = "(p+q)*(m-n)";
    cout << "Infix  : " << infix << endl;
    string postfix = Infix_to_Postfix(infix);
    cout << "Postfix: " << postfix << endl;

    cout << endl;

    postfix = "pq+mn-*";
    cout << "Postfix: " << postfix << endl;
    infix = Postfix_to_Infix(postfix);
    cout << "Infix  : " << infix << endl;

    cout << endl;

    infix = "(p+q)*(m-n)";
    cout << "Infix  : " << infix << endl;
    string prefix = Infix_to_Prefix(infix);
    cout << "Prefix : " << prefix << endl;

    return 0;
}
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

/*Sabse pehle infix to postfix aata hai phir usme reversal aur extra power aur equality condition laga ke infix to prefix banta hai*/
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
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
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

/*Postfix(t2 pehle) aur prefix(t1 pehle) to Infix me bas jaise hi operator aaye stack ke top ke do elements uthao aur usko concantate karke stack me wapas daal do
Way to remember -> prefix me pre isliye t1 pehle*/
string Postfix_to_Infix(string s)
{
    int i = 0, n = s.length();
    stack<string> st;

    while (i < n)
    {
        if (isalnum(s[i]))
            st.push(string(1, s[i]));
        else
        {
            string t1 = st.top();
            st.pop();

            string t2 = st.top();
            st.pop();

            string cont = "(" + t2 + string(1, s[i]) /*Jo bhi operator ya expression hoga uss samay string me*/ + t1 + ")";
            st.push(cont);
        }
        i++;
    }
    return st.top();
}

/*In this we iterate form the back*/
string Prefix_to_Infix(string s)
{
    int n = s.size(), i = n - 1;
    stack<string> st;

    while (i >= 0)
    {
        if (isalnum(s[i]))
            st.push(string(1, s[i]));

        else
        {
            string t1 = st.top();
            st.pop();

            string t2 = st.top();
            st.pop();

            string cont = '(' + t1 + string(1, s[i]) + t2 + ')';
            st.push(cont);
        }
        i--;
    }
    return st.top();
}

/*Post to pre op + t2 + t1 and i=0*
Pre to Post t1 + t2 + op and i = n-1*/
string Postfix_to_Prefix(string s)
{
    int i = 0, n = s.size();
    stack<string> st;

    while (i < n)
    {
        if (isalnum(s[i]))
            st.push(string(1, s[i]));
        else
        {
            string t1 = st.top();
            st.pop();

            string t2 = st.top();
            st.pop();

            string cont = string(1, s[i]) + t2 + t1;
            st.push(cont);
        }
        i++;
    }
    return st.top();
}

string Prefix_to_Postfix(string s)
{
    int n = s.size(), i = n - 1;
    stack<string> st;

    while (i >= 0)
    {
        if (isalnum(s[i]))
            st.push(string(1, s[i]));
        else
        {
            string t1 = st.top();
            st.pop();

            string t2 = st.top();
            st.pop();

            string cont = t1 + t2 + string(1, s[i]);
            st.push(cont);
        }
        i--;
    }
    return st.top();
}

int main()
{
    // Infix   → Postfix
    string infix = "(p+q)*(m-n)";
    cout << "Infix  : " << infix << endl;
    string postfix = Infix_to_Postfix(infix);
    cout << "Postfix: " << postfix << endl;

    cout << endl;

    // Postfix → Infix
    postfix = "pq+mn-*";
    cout << "Postfix: " << postfix << endl;
    infix = Postfix_to_Infix(postfix);
    cout << "Infix  : " << infix << endl;

    cout << endl;

    // Infix   → Prefix
    infix = "(p+q)*(m-n)";
    cout << "Infix  : " << infix << endl;
    string prefix = Infix_to_Prefix(infix);
    cout << "Prefix : " << prefix << endl;

    cout << endl;

    // Prefix  → Infix
    prefix = "*+pq-mn";
    cout << "Prefix : " << prefix << endl;
    infix = Prefix_to_Infix(prefix);
    cout << "Infix  : " << infix << endl;

    cout << endl;

    // Prefix → Postfix
    prefix = "*+pq-mn";
    cout << "Prefix  : " << prefix << endl;
    postfix = Prefix_to_Postfix(prefix);
    cout << "Postfix : " << postfix << endl;

    cout << endl;

    // Postfix → Prefix
    postfix = "pq+mn-*";
    cout << "Postfix : " << postfix << endl;
    prefix = Postfix_to_Prefix(postfix);
    cout << "Prefix  : " << prefix << endl;
    return 0;
}
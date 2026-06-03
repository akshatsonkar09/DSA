#include <bits/stdc++.h>
using namespace std;

// VVV IMP Concept is ki bina loop lagaye agar top element save ho jaye toh mera kaam ho jayega isliye recusrion istemal kiya aur usme top ki value hold karwa di

class REVERSESTACK
{
public:
    void insertAtBottom(stack<int> &st, int val)
    {
        if (st.empty())
        {
            st.push(val);
            return;
        }

        int topVal = st.top();
        st.pop();

        insertAtBottom(st, val);
        st.push(topVal);
    }

    // Function to reverse the stack
    void reverseStack(stack<int> &st)
    {
        // Base case: If stack is empty, return
        /*$$*/ if (st.empty())
            return;

        // Pop the top element
        int topVal = st.top();
        st.pop();

        // Recursively reverse the remaining stack
        reverseStack(st); /*$$*/ // itna part bas itna kehta hai ki jab tak stack empty nahi ho rahi hai tab tak nikaalte raho

        // Insert the popped element at the bottom
        insertAtBottom(st, topVal);
    }
};

class SORTSTACK
{
public:
    void sortinsert(stack<int> &s, int temp)
    {
        // Base case: if the stack is empty or temp is larger than the top element
        if (s.empty() || s.top() <= temp)
        {
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
    void sortStack(stack<int> &s)
    {
        if (!s.empty())
        {
            int temp = s.top();
            s.pop();

            sortStack(s); // ab second top element aayega isme aur phir third and so on

            sortinsert(s, temp);
        }
    }
};

class PRINTNAME
{
public:
    // Recursive function to print name count times
    void printName(string name, int count, int N)
    {
        // Base case: if count equals N, stop recursion
        if (count == N)
            return;

        // Print the name
        cout << name << "\n";

        // Recursive call with incremented count
        printName(name, count + 1, N);
    }
};

class SUMOFNATURALNUMBER
{
public:
    // Recursive function to find sum of first N natural numbers
    int sumOfNaturalNumbers(int N)
    {
        // Base case: if N is 1, return 1
        if (N == 1)
        {
            return 1;
        }
        // Recursive case: current number + sum of previous numbers
        return N + sumOfNaturalNumbers(N - 1);
    }
};

class GENERATEALLBINARY
{
public:
    void generateallbinarystrings(int n, string curr)
    {
        // Base Case
        if (curr.length() == n)
        {
            // result.push_back(curr);
            cout << curr << endl;
            return;
        }

        generateallbinarystrings(n, curr + '0');

        // if curr.back != '1' then add
        generateallbinarystrings(n, curr + '1');
    }
};

class GENERATEPARENTHESIS
{
public:
    void generate(string curr, int open, int close, vector<string> &ans, int n)
    {

        // Base Case
        if (open == n && close == n)
        {
            ans.push_back(curr);
            return;
        }

        if (open == close && open < n)
            generate(curr + '(', open + 1, close, ans, n);

        if (open > close && open < n)
        {
            generate(curr + '(', open + 1, close, ans, n);
            generate(curr + ')', open, close + 1, ans, n);
        }
        if (open == n && close < n)
            generate(curr + ')', open, close + 1, ans, n);
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string curr = "";

        generate(curr, 0, 0, ans, n);
        return ans;
    }
};

class PRINTPOWERSET
{
public:
    void generate(string curr, vector<string> &res, string str, int i, int n)
    {
        // Base case
        if (i == n)
        {
            res.push_back(curr);
            return;
        }

        generate(curr + str[i], res, str, i + 1, n);
        generate(curr, res, str, i + 1, n);
    }

    void generateefficient(string curr, vector<string> &res, string &str, int i)
    {
        if (i == str.size())
        {
            res.push_back(curr);
            return;
        }
        curr.push_back(str[i]);
        generateefficient(curr, res, str, i + 1);
        curr.pop_back();
        generateefficient(curr, res, str, i + 1);
    }

    vector<string> printpowerset(string str)
    {
        vector<string> res;
        string curr = "";
        int n = str.length();

        generate(curr, res, str, 0, n);
        return res;
    }

    // void generatepowerset (string str) {
    //     for (int mask = 0; mask <= (1<<str.size()); mask++)  //This will run 2^n times
    //     {
    //         for (int i = 0; i < str.size(); i++)
    //         {
    //             if(mask & (1<<i))
    //         }

    //     }

    // }
};

class PRINTALLSUBSETS /*VVVVVVV IMP*/
{
public:
    // so i am thinking in terms of copying that I need to give this data structure to keep he value but recusrion actually stores it in form of state

    void func(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr, int i)
    {
        if (i == nums.size())
        {
            res.push_back(curr);
            return;
        }

        // include
        curr.push_back(nums[i]);
        func(nums, res, curr, i + 1);

        // exclude
        curr.pop_back();
        func(nums, res, curr, i + 1);
    }

    vector<vector<int>> printallsubsets(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        vector<int> curr;
        func(nums, res, curr, 0);
        return res;
    }
};

class COUNT_ALL_SUBSEQUENCES_WITH_K
{
public:
    void func(vector<int> &nums, int sum, int target, int &ans, int i)
    {
        // Base Case
        if (i == nums.size())
        {
            if (sum == target)
            {
                ans++;
            }
            return;
        }

        /*
        //include
        curr.push_back(nums[i]);
        func(nums, curr, sum+nums[i], target, ans, i+1);

        //exclude
        curr.pop_back();
        func(nums, curr, sum, target, ans, i+1);
        */
        // This is extra work as we never needed subset use current only if we need to print the sets but we only need to calculate sum so curr is not needed

        // include
        func(nums, sum + nums[i], target, ans, i + 1);

        // exclude
        func(nums, sum, target, ans, i + 1);
    }

    int countSubsequenceWithTargetSum(vector<int> &nums, int target)
    {
        // vector<int> curr;
        int ans = 0;
        func(nums, 0, target, ans, 0);
        return ans;
    }
};


class CHECK_IF_SUBSEQUENCES_WITH_K
{
public:
    bool func(vector<int> &nums, int sum, int target, int i)
    {
        // Base Case
        if (i == nums.size())
        {
            if (sum == target) return true;
            return false;
            //return sum==target;   even smaller
        }

        bool include = func(nums, sum + nums[i], target,  i + 1);
        bool exclude = func(nums, sum, target, i + 1);

        return include || exclude;
        // return func(nums, sum + nums[i], target,  i + 1) | func(nums, sum, target, i + 1)      EVEN better
    }

    bool countSubsequenceWithTargetSum(vector<int> &nums, int target)
    {
        return func(nums, 0, target, 0);
    }
};



int main()
{

    return 0;
}
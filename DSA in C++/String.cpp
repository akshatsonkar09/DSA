#include <iostream>
#include <bits/stdc++.h>

using namespace std;



class Solution {
    /*
unordered_map is used for O(1) frequency counting.
We cannot directly sort a map/unordered_map by frequency values,
so we copy the data into a vector and sort the vector.
    
    SO we are making a hash map storing the frequency, then putting it all in a vector so that we can use sort and then appending it
    */
private:
    static bool cmp(const pair<char,int> &a, const pair<char,int> &b) {
        return a.second > b.second;
    }
    /*
    Q1-> why static?

    Q2-> why const?
    Ans-> Meaning - I promise not to modify a or b. Comparators are only comparing not modify. So a.second = 100 will not throw error

    Q3-> Why []? 
    Ans-> [] starts a lambda. Think of it as an anonymous function.

    Q4-> Why a>b how it tells descending?
    Ans-> Sort asks should 'a' come before 'b'. comparator answers-> return a>b
    */
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i]]++;
        }

        // vector<pair<int,char>> v;  this is not recommended as the char,int and int,char will cause problem in auto iterate
        vector<pair<char,int>> v;

        for (auto it: freq)
        {
            v.push_back(it);
            //v.push_back({it.second,it.first});    If you want to determine value custom by yourself
        }

        sort(v.begin(), v.end(), cmp);

        string ans = "";

        for (auto it: v)
        {
            //string& append(n count, char ch); basically ch times n append;
           ans.append(it.second,it.first);
        }

        return ans;
    }
};



int main() {
    
    return 0;
}
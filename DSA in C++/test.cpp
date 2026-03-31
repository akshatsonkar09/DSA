#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int hash[256];
    for (int i = 0; i < 256; i++)
    {
        hash[i] = -1;
    }
    
    int longest;
    int left = 0, right = 0;
    while (right < s.length())
    {
        if (hash[s[right]] != -1)
        {
            left = max(hash[s[right]]+1,left);
        }
        int length = right-left+1;
        
        longest = max(length,longest);
        hash[s[right]] = right;
        right++;
    }
    return longest; 
}

int main()
{

    return 0;
}
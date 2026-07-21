#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();

        //augment string
        s.insert(s.begin(),'1');
        s.insert(s.end(),'1');

        vector<int> pos;

        for (int i = 1; i <= n; i++) 
            if(s[i] == '1') pos.push_back('i');


        int maxi = -1;
        for (int i = 1; i+1 < pos.size(); i++)
        {
            int len = pos[i+1] - pos[i-1] - 1;
            maxi = max(maxi, len);
        }
        
        return maxi;
    }
};

int main()
{
    return 0;
}
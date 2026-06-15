#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class FRUIT_INTO_BASKET
{
private:

public:
    int totalFruit2Ntime(vector<int>& fruits,int k) {
        int maxlen = 0;
        int left=0, right=0;

        unordered_map<int,int> mp;

        while (right < fruits.size())      
        {
            mp[fruits[right]]++;

            while (mp.size() > k) {
                mp[fruits[left]]--;

                if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
            }

            maxlen = max(maxlen, right-left+1);
            right++;
        }
        return maxlen;
    }

    int totalFruitNtime(vector<int> &fruits, int k) {
        int maxlen = 0;
        int left=0, right=0;

        unordered_map<int,int> mp;

        while (right < fruits.size())      
        {
            mp[fruits[right]]++;

            while (mp.size() > k) {
                mp[fruits[left]]--;

                if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
            }

            maxlen = max(maxlen, right-left+1);
            right++;
        }
        return maxlen;
    }
};



int main() {
    
    return 0;
}
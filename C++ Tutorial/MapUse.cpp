#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


int main() {

    string s = "XIV";

 unordered_map <char,int> mp;
 mp = { {'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};

for (int i = 0; i < s.size(); i++)
{
    cout<< mp[s[i]] << " ";
}

 


    return 0;
}
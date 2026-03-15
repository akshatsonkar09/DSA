#include <iostream>
#include <bits/stdc++.h>    

using namespace std;

//Important way on how traversing can work in a string vector kinda like a multi dimensional array
int main() {
    vector <string> s = {"flower","flow","flight"};

    for (int i = 0; i < /*3*/ s.size(); i++)         //For traversing thru the words
    {
        for (int j = 0; j < /*6*/s[i].length(); j++)     //For traversing thru letters in the words
        {
            cout << s[i][j] << endl;
            
        }
        cout<< endl;
        
    }

    cout << s.size()<< endl;
    cout << s[0].length()<< endl;

    // Slicing in C++ 
    // This is wrong - s[0][0:3] (like we do in python)
    // In c++ we do 

    cout<< s[0].substr(0,3)<< endl;

    string ans = "";



    for (int i = 0; i < s[0].length(); i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j][i] != s[j+1][i])
            {
                cout << ans;
            }
        }
        ans += s[0][i];
    }

    cout << ans << endl;
    
    


    
    return 0;
}
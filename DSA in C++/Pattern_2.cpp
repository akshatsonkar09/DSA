#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
    int n = 3;
    for(int i = 0; i <= n; i++) {
            for (int k = i+1; k > 0; k--)
            {
                cout<< "  ";
            }
            for(int j = i + 1; j <= n; j++) {
                cout << "* ";
            }
            cout << endl;
        }
    return 0;
}
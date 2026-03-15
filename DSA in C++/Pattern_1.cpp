#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printpattern (int n) {
    // int count;
    for (int i = 0; i < n; i++)
    {
        // count = 1;
        for (int j = 0; j <= ((n/2)-i+1); j++)
        { 
            cout << "  ";
        }
        for (int k = 0; k <= i; k++)
        {
            cout<< "* ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    printpattern(n);

    return 0;
}
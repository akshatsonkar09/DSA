#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string ConvertToBinary(int n) {
    string bin = "";
    while (n!=1)
    {
        if (n%2 == 1) bin +='1';
        else bin += '0';
        n = n/2;
    }
    reverse(bin);
    return bin;
}

int ConvertToDecimal (string bin) {
    int len = bin.length();
    int dec = 0;
    for (int i = len-1; i >= 0; i--)
    {
         if(bin[i] == '1') num+= 
    }
    
    
}

int main() {
    
    return 0;
}
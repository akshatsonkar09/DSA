#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// This will throw an error because in c++ array decays into a pointer which means that it is a pointer integer

// int countnumber(int arr[], int val) {
//     int count = 0;

//     for (auto i: arr)
//     {
//        if (i == val)
//        {
//         count++;
//        }
//     }
//     return count;
// }

int countnumber(int arr[], int val, int n)
{
    int count = 0;
    // int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            count++;
        }
    }
    return count;
    // This has O(n) time complexity and for big number (let's say Q) time complexity sky rockets to O(Qxn) which can go upto minutes
}

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    /******NUMBER HASHING START******/
    int arr[] = {2, 5, 2, 5, 7, 3, 8, 2, 9, 6, 4, 8, 9};

    int n = sizeof(arr) / sizeof(int);

    /*Precomputation Start*/
    int hashnum[20] = {0};
    /*Eg-> for val till 13 we need a hash array of size 14 (0-13) hence need to make an hash array of n+1*/

    for (int i = 0; i < n; i++)
    {
        hashnum[arr[i]] += 1;
    }
    /*Precomputation End*/

    printarray(arr, 13);
    cout << "Number of times '2' occurs: " << hashnum[2] << endl;
    /******NUMBER HASHING END******/

    /******NUMBER HASHING THRU MAP START******/
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++; // It will only store elements in the array and not in range(like 0-13) hence it is more memory efficient
    }
    cout << "Number of times '2' occurs: " << mp[2] << endl;

    for (auto i : mp)
    {
        cout << i.first << "->" << i.second << endl; // Your values will be displyed randomly as unordered map is used
    }

    // Same can be done to hash character

    /******NUMBER HASHING THRU MAP END******/

    /******CHARACTER HASHING START******/
    string s = "akshatsonkar";

    // Precompute
    int hashchar[26] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        hashchar[s[i] - 'a']++;

        // s[i] is a character which will be changed into number and the hash array will increase a number in that index. Basically the concept of character being converted into numbers thanks to ASCII Value is the reason we are able to do it
    }

    char c = 'a';
    // cin >> c;

    cout << "Number of times 'a' occurs: " << hashchar[c - 'a'] << endl;

    /******CHARACTER HASHING END******/

    /******MAX & MIN FREQUENCY START******/

    // int arr[] = {2, 5, 2, 5, 7, 3, 8, 2, 9, 6, 4, 8, 9};     This is array

    /*
    int max_freq = INT_MAX;
    int min_freq = INT_MIN;
    */
    // Concept Error

    int max_freq = INT_MIN;
    int min_freq = INT_MAX;
    int max_ele;
    int min_ele;

    for (int i = 0; i < n; i++)
    {
        max_freq = max(max_freq, hashnum[i]);
        min_freq = min(min_freq, hashnum[i]);
    }

    cout << "Max Frequency is " << max_freq /*<< " of number "<<(You need to use if else instead of max/min to also print the element)*/ << endl;
    cout << "Min Frequency is " << min_freq << /* " of number "<<*/ endl;

    /******MAX & MIN FREQUENCY END******/

    return 0;
}
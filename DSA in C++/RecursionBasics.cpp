#include <iostream>
#include <bits/stdc++.h>

using namespace std;

    // Recursive function to print name count times
    void printName(string name, int count, int N) {
        // Base case: if count equals N, stop recursion
        if (count == N)
            return;

        // Print the name
        cout << name << "\n";

        // Recursive call with incremented count
        printName(name, count + 1, N);
    }


    // Recursive function to find sum of first N natural numbers
    int sumOfNaturalNumbers(int N) {
        // Base case: if N is 1, return 1
        if (N == 1) {
            return 1;
        }
        // Recursive case: current number + sum of previous numbers
        return N + sumOfNaturalNumbers(N - 1);
    }

        // Function to reverse the array in-place
    void reverseArray(vector<int>& arr) {
        // Initialize pointer to the beginning of the array
        int p1 = 0;

        // Initialize pointer to the end of the array
        int p2 = arr.size() - 1;

        // Loop until the two pointers meet in the middle
        while (p1 < p2) {
            // Swap the elements at p1 and p2
            swap(arr[p1], arr[p2]);

            // Move the left pointer one step to the right
            p1++;

            // Move the right pointer one step to the left
            p2--;
        }
    }
int main() {
    
    return 0;
}
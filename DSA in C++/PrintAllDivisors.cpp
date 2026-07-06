#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> getDivisors(int N) {

        vector<int> res;

        // Loop from 1 to square root of N
        for (int i = 1; i * i <= N; i++) {
            // Check if i divides N
            if (N % i == 0) {
                // Add i to the result
                res.push_back(i);

                // If N / i is different from i, add N / i too
                if (i != N / i) {
                    res.push_back(N / i);
                }
            }
        }
        return res;
    }
};

int main() {
}

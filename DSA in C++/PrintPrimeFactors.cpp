#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class PRINT_ALL_PRIMES_OF_N {
    public:
    //This is same method as Long Factorizatin you use to find primes
    vector<int> primeFactors(int n) {
        vector<int> factors;
        
        //If divisble by 2 then 2 is a prime so we can keep on dividing by 2 and removing all powers of 2 and reducing number at exponential rate
        if (n % 2 == 0) {
            factors.push_back(2);
            while (n % 2 == 0)
            n /= 2;
        }
        
        //Now we will need to check only odd numbers saving half of the time
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                factors.push_back(i);
                
                //Remove all powers of i
                while (n % i == 0)
                n /= i;
            }
        }
        
        if (n > 1)
        factors.push_back(n);
        
        return factors;
    }  
};


class COUNT_PRIMES_UPTO_N {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;

        vector<int> prime (n,1);
        prime[0] = prime[1] = 0;

        for (int i = 2; i*i < n; i++)
        {
            if(prime[i]) {
                for (int j = i*i; j < n; j+=i) prime[j] = 0;
            }
        }
        
        int cnt = 0;
        for (int i = 2; i < n; i++) if(prime[i]) cnt++;
        return cnt;
    }
};

int main() {
    
    return 0;
}


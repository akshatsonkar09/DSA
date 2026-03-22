#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, c, k;
        cin >> n >> c >> k;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        
        long long current_c = c, remaining_k = k;
        
        for (int i = 0; i < n; i++) {
            if (a[i] <= current_c) {
                long long flops = min(remaining_k, current_c - a[i]);
                current_c += a[i] + flops;
                remaining_k -= flops;
            } else {
                break;
            }
        }
        cout << current_c << endl;
    }
    return 0;
}
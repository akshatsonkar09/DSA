#include <iostream>
#include <vector>

using namespace std;

void showArray(vector<int> v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << "\n";
}
int main() {
    
    vector <int> v = {2,4,6,8,10};
    showArray(v);

    //For insertion of number
    v.insert(v.begin() + 2, 5);
    showArray(v);
    
    // cout <<v << endl;    This is not possible
    
    //For deletion of number
    v.erase(v.begin() + 3);
    showArray(v);

    return 0;
}
#include <iostream>
#include<vector>

using namespace std;

vector<int> func(int arr1[], int arr2[], int n, int m) {
    int i = 0, j=0;
    vector<int> v;

    while(i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            if(v.empty() || v.back() != arr1[i]) {
                v.push_back(arr1[i++]);
            }
        }
        else if (arr1[i] > arr2[j]) {
            if(v.empty() || v.back() != arr2[j]) {
                v.push_back(arr2[j++]);
            }
        }
        else {
            if(v.empty() || v.back() != arr2[j]) {
                v.push_back(arr1[i]);
                i++;
                j++;
            }
        }

    while (i < n)
    {
        if(v.empty() || v.back() != arr1[i]) {
            v.push_back(arr1[i]);
        }
        i++;
    }

    while (j < m)
    {
        if(v.empty() || v.back() != arr2[j]) {
            v.push_back(arr2[j]);
        }
        j++;
    }
    

}
}

int main() {
    cout << "Hello, World!" << endl;
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {2,3,4,4,5};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    func(arr1, arr2, n, m);

    return 0;
}
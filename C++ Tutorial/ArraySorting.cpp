#include <iostream>

using namespace std;
//Very Important

int main() {
    int arr[] = {0,1,1,2,4,6,7,7,9};

    int n = sizeof(arr)/sizeof(int);

    int j = 1;

    for(int i =1;i<n;i++) {
        if (arr[i] != arr[j-1])
        {
            arr[j] = arr[i];
            j++;
        }
        }

for(auto i:arr) {
    cout<< i << " ";
}


    return 0;
}
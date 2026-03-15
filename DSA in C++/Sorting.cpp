#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printvector(vector <int> arr)
{
for (auto i: arr)
{
   cout << i << " ";
}
cout << endl;
}

void SelectionSort (vector<int> &arr) {     //swap index with min
    int n = arr.size();
    for (int i = 0; i < n-1; i++)   //n-1 cause last ke liye mujhe karna hi nahi hai
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min]) min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void BubbleSort( vector<int> &arr) {     //Largest ko last me daal dete hai
    int n = arr.size();
    int runs = 0;
    for (int i = 0; i < n-1; i++)
    {
        int didswap = 0;
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didswap = 1;
                runs++;
            }
        }
        if(didswap == 0) break;     //could have just returned if no runs was there
    }
    cout << runs;
}
void InsertionSort(vector<int> &arr, int n) {   //Smallest le kar usko first par daal dete hai
int n = arr.size();
for (int i = 0; i < n; i++)
{
    int j = i;
    while (j > 0 && arr[j-1] > arr[j])
    {
        int temp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = temp;
        j--;
    }
    
}

}

int main()
{
    vector<int> arr = {5, 2, 9, 1, 5};
    
    // greater <int> (3,2,5,4,9,7);
    //This is basic sorting using sorting function where we can decide till how long we want to sort our array
    printvector(arr);
    sort(arr.begin(), arr.end());
    printvector(arr);
    cout << endl;
    
    
    //This is to sort in descending order
    arr = {5, 2, 9, 1, 5};
    printvector(arr);
    sort(arr.begin(), arr.end(), greater<int>());
    printvector(arr);
    cout << endl;
    
    
    //This is to make custom sorts using comparator
    arr = {5, 2, 9, 1, 5};
    printvector(arr);
    sort(arr.begin(), arr.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });
    printvector(arr);
    cout << endl;
    
    //Selection Sort
    arr = {5, 2, 9, 1, 5};
    printvector(arr);
    SelectionSort(arr);
    printvector(arr);
    cout << endl;
    


}
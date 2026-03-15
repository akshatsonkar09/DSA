#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int LinearSearch(vector<int> &arr, int val)
{
    int index = 0;
    for (auto i : arr)
    {
        if (i == val)
        {
            return index;
        }
        index++;
    }
    return -1;
}

// Both are Correct
// Works on sorted and unsorted all

// int LinearSearch(vector<int> &arr, int val) {
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (arr[i] == val)
//         {
//             return i;
//         }
//         }
//         return -1;
// }

// Only works on sorted
int BinarySearch(vector<int> arr, int val)
{
    int low, mid, high;

    low = 0;
    high = arr.size() - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == val)
        {
            return mid;
        }
        else if (arr[mid] > val)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int BinarySearchRecursive(vector<int> &arr, int low, int high, int val)
{
    if (low > high)
        return -1; // Important edge case for when search space exhausted → element not found And I FORGOT TO WRITE IT
    int mid;
    mid = (low + high) / 2;
    if (arr[mid] == val)
        return mid;
    else if (arr[mid] > val)
        return BinarySearchRecursive(arr, low, mid - 1, val);
    else
        return BinarySearchRecursive(arr, mid + 1, high, val);
}

int BinarySearchProfessional(vector<int> &arr, int val)
{
    auto it = lower_bound(arr.begin(), arr.end(), val);
    return (it != arr.end() && *it == val) ? it - arr.begin() : -1;

    /*
    Very Important Explanation

    lower_bound is an in-built algorithm function which gives back address value, because it is a pointer. This is an iterator.

    The ternary operator says that if -> 'it' is not equal to end of index and dereferenced 'it' is equal to val then print it-arr.begin() which is something like(explained below) else -> return -1.

    Example -
    arr[0] at address 1000
    arr[1] at address 1004
    arr[2] at address 1008
    arr.begin() = 1000
    it          = 1012   // say it points to arr[3]
    it - arr.begin() = 1012 - 1000 = 12 but this is scaled below automatically by c++ when returning output :-

    (1012 - 1000) / sizeof(int) = 3(What C++ actually return) (But this is not what C++ do exactly. This is a mental formula just for us)
    In reality -> C++ gives back number of elements between the two iterators as result.

    Scaling Only works when
    1) You are subtracting pointers or iterators
    2) Both point into the same contiguous array
    3) The type is known at compile time
    4) The iterator is random-access
    Examples:
        int*
        vector<T>::iterator
        deque<T>::iterator

        Not valid for:
        list
        forward_list
        set
        */
}

int LinearSearchProfessional(vector<int> &arr, int val)
{
    auto it = find(arr.begin(), arr.end(), val);      // This is a find function
    return (it == arr.end()) ? -1 : it - arr.begin(); // This is a ternary operator which says if -> 'it' == last value of vector return -1. Else -> return it minus start of vector (Same scaling and stuff used)
}

int Upper_Bound(vector<int> &arr, int val)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int mid;
    int ans = n;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] > val) // Difference between lower and upper is just changing to arr[mid] >= val
        {
            high = mid - 1;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int Lower_Bound(vector<int> &arr, int val)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int mid;
    int ans = n;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] >= val) // Difference between lower and upper is just changing to arr[mid] > val
        {
            high = mid - 1;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int Search_Insert_Index(vector<int> &arr, int val)
{
    return lower_bound(arr.begin(), arr.end(), val) - arr.begin();
}

pair<int, int> firstandlastoccurence(vector<int> &arr, int val)
{
    int n = arr.size();

    int lb = Lower_Bound(arr, val);
    if (lb == n || arr[lb] != val)
        return {-1, -1};

    return {lb, Upper_Bound(arr, val) - 1};
}

int Rotated_Array_Search(vector<int> &arr, int val)
{
    int low = 0, high = arr.size() - 1;
    int mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == val)
            return mid;

        if (arr[mid] == arr[low] && arr[mid] == arr[high]) // Important
        {
            low = low + 1;
            high = high - 1;
        }

        if (arr[low] <= arr[mid])
        {
            if (arr[mid] >= val && arr[low] <= val)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (arr[mid] <= val && arr[high] >= val)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
}
int Minimum_Rotated_Array(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int mid;
    int ans = INT_MAX;

    while (low <= high)
    {
        // Window already sorted
        if (arr[low] <= arr[high])
        {
            ans = min(ans, arr[low]);
            break;
        }

        mid = low + (high - low) / 2;

        if (arr[low] <= arr[mid]) /*Only correct condition because this proves that left is sorted and thinking ->
  Negative knowledge (“left is broken”). Binary search requires positive knowledge (“this half is definitely sorted”). Is wrong.*/
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            ans = min(ans, arr[mid]);
        }
    }
    return ans;
}
int Count_Rotated_Array(vector<int> &arr) // Lowest value ka index hi no of times rotated hota hai like {4,5,6,1,2} so 1 at index 3 hence three times rotated
{
    int low = 0, high = arr.size() - 1;
    int mid;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high)
    {
        // Window already sorted
        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }
            break;
        }

        mid = low + (high - low) / 2;

        if (arr[low] <= arr[mid]) /*Only correct condition because this proves that left is sorted and thinking ->
  Negative knowledge (“left is broken”). Binary search requires positive knowledge (“this half is definitely sorted”). Is wrong.*/
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
                low = mid + 1;
                index = low;
            }
        }
        else
        {
            if (arr[mid] < ans)
            {
                ans = arr[mid];
                high = mid - 1;
                index = mid;
            }
        }
    }
    return index;
}

// Odd/Even dhundte samay bhul index = 0 se start hota hai yeh bhul gaya
// Edge Cases bhul gaya
// Forgot low and high value
// Wrote n instead of 0 or n-1 in first edge case
int single_element_in_sorted_array(vector<int> &arr)
{
    int n = arr.size();

    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int low = 1, high = n - 2, mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            return arr[mid];

        else if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || ((mid % 2 == 0 && arr[mid] == arr[mid + 1])))
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

int peak_element(vector<int> &arr)
{
}

int main()
{

    vector<int> v = {3, 6, 8, 9, 11, 24};

    cout << "Binary Search: " << BinarySearch(v, 24) << endl;
    cout << "Linear Search: " << LinearSearch(v, 9) << endl;

    cout << "Linear Search Professional: " << LinearSearchProfessional(v, 9) << endl;
    cout << "Binary Search Professional: " << BinarySearchProfessional(v, 9) << endl;

    cout << "Binary Search Recursive: " << BinarySearchRecursive(v, 0, 5, 9) << endl;

    cout << "Binary Search In-built(only 0 or 1): " << binary_search(v.begin(), v.end(), 11) << endl;
    // In built function for binary search but only tell whether it is there or not. Does not tell which position. You also need to include algorithm
    // DANGER --> If the array isn’t sorted, the answer is garbage—but looks correct. That’s the dangerous part.

    cout << "Upper Bound of 5: " << Upper_Bound(v, 5) << endl;
    cout << "Lower Bound of 5: " << Lower_Bound(v, 9) << endl;
    // lower_bound(v.begin(),v.end(),9);   //This is a pointer which points towards the memory address of the answer
    // cout << *(lower_bound(v.begin(),v.end(),9)) << endl;

    // For searchindex type questions , use lower bound
    cout << "Index to put value 10: " << Search_Insert_Index(v, 10) << endl;

    v = {7, 8, 9, 1, 2, 3, 4, 5, 6};

    cout << "Rotated Sorted Array Search for value 1:" << Rotated_Array_Search(v, 1);

    v = {1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 8};
    cout << "Single element in sorted list is " << single_element_in_sorted_array << endl;

    return 0;
}
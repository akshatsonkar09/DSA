#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// child = i   parent = (i-1)/2
// parent = i      left/right child = 2*i+1||2*i+2

class BinaryHeap
{
public:
    int capacity;
    int size;
    int *arr;

    BinaryHeap(int cap)
    {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int leftchild(int i)
    {
        return 2 * i + 1;
    }

    int rightchild(int i)
    {
        return 2 * i + 2;
    }

    void Insert_in_Binary_Heap(int x)
    {

        // Checking if heap is full
        if (size == capacity)
        {
            cout << "Binary Heap Overflow" << endl;
            return;
        }

        arr[size] = x; // Adding at last

        // Taking values needed for comparison
        int key = size;
        size++;

        // Checking parent and swapping if needed
        while (key != 0 && arr[parent(key)] > arr[key])
        {
            swap(arr[parent(key)], arr[key]);
            key = parent(key);
        }
    }

    void Deletion_of_Root_in_Binary_Heap(int x)
    {
        // Check underflow
        if (size == 0)
        {
            cout << "Binary heap Undeflow" << endl;
            return;
        }

        // Bring root at last & Taking values needed for comparison
        arr[0] = arr[size-1]; // or swap(arr[0], arr[size]);
        size--;

        int key = 0;

        while (key < size)
        {
            if (leftchild(key) && arr[leftchild(key)] > arr[key])
            {
                swap(arr[leftchild(key)], arr[key]);
                key = leftchild(key);
            }
            else if (rightchild(key) && arr[rightchild(key)] > arr[key])
            {
                swap(arr[rightchild(key)],arr[key]);
                key = rightchild(key);
            }
            else return;
        }
    }

    void printheap(int arr[])
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    return 0;
}
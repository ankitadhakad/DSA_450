#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
// Example 1:
// Input: 
// N = 5
// arr[]= {0 2 1 2 0}
// Output:
// 0 0 1 2 2
// Explanation:
// 0s 1s and 2s are segregated 
// // into ascending order.

// brute force
void sort012(int arr[], int n)
{
    sort(arr, arr + n);
}

// approach 2->
// using separate data structure for storing 0 1 and 2 separately and bringing
// them together

// approach-3
// counting 0 1 and 2 in single loop and then adding them to array one bye one

// approach -4
// We will use Three-way partitioning method.
// This approach will divide the array into four sections using three-pointers,
// i.e., Low, Mid, and High and will sort the array in a single traversal.
void sort012opt(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid = 0;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
            mid++;
        else // if 2
        {
            swap(arr[mid], arr[high]);
             high--;
        }
    }
}
void print(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n = 0;

    cout << "Enter Size Of the Array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements of Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    print(arr, n);
    cout << endl;
    sort012opt(arr,n);
    print(arr,n);
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// {
//     Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
// Example 1:
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
//    }

// approach-1
// storing the k+1 to n-1 elements and 0 to k elements separately and then combining them together

// approach-2
// reverse 0 to k part || 0 to n-k-1
// reverse k+1 to n-1 part || n-k to n-1
// reverse whole array
void reverse(int arr[], int start, int end)
{
    int left = start;
    int right = end;
    while (left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

void rotate(int nums[], int k, int n)
{
    k = k % n;
    if (k < 0)
    {
        k += n;
    }
    reverse(nums, 0, n - k - 1); // reverse(nums, 0, n - k - 2);//for left rotation
    reverse(nums, n - k, n - 1); // reverse(nums, n - k-1, n - 1);//for left rotation
    reverse(nums, 0, n - 1);     // same
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
    int arr1[n];
    cout << "Enter elements of Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cout << endl;
    print(arr1, n);
    cout << endl;

    int k = 0;
    cout << "Enter The value of k" << endl;
    cin >> k;

    rotate(arr1, k, n);
    print(arr1, n);
    cout << endl;

    return 0;
}
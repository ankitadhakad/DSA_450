#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// {
//  Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.
// Example 1:
// Input: nums = [1,3,4,2,2]
// Output: 2
// }

//approach 1 = sort and traverse
//approach 2 = using set data structur
//approach 3 = binary search || two pointers without sorting
int find(int arr[],int n)
{
    int low = 1;
    int high = n-1;
    
    while(low<high)
    {
        int mid = low +(high-low)/2;
        int count = 0;
        for(int i=0; i<n; i++)
        {
            if(arr[i] <= mid)
            count++;
        }
        if(count <= mid)
        low = mid+1;
        else high = mid;

    }
    return low;
}



//approach 4//O(n) without sorting
int findDuplicate(int nums[],int n) {
        
        for(int i = 0; i < n; ++i)
        {
            int idx = abs(nums[i]);
            
            if(nums[idx] < 0)
                return idx;
            
            nums[idx] = -nums[idx];
        }
        
        return n;
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

    cout<<find(arr1,n)<<endl;

    return 0;
}
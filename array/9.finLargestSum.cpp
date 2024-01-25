#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//approach 1->brute force O(n^2)

//approach2->kadane's algorithm
int maxSubArray(int arr[],int n)//circular array->leetcode
{
    int currSum = 0;
    int maxSum = INT_MIN;
    int i=0;
    while(i<n)
    {
        currSum+=arr[i];
        if(currSum > maxSum)
        maxSum = currSum;
        if(currSum < 0)
        currSum = 0;
        i++;
    }
    return maxSum;
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
    cout<<maxSubArray(arr1,n);
    // cout<<maxSum;
    return 0;
}
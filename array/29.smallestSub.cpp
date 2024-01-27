#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach 1 O(n^2)
int smallestSubWithSumI(int arr[], int n, int x)
{
    int minLength = n + 1;
    for (int start = 0; start < n; ++start)
    {
        int currSum = arr[start];
        if (currSum > x)
            return 1; // Single element is greater than x
        for (int end = start + 1; end < n; ++end)
        {
            currSum += arr[end];
            if (currSum > x && (end - start + 1) < minLength)
            {
                minLength = end - start + 1;
            }
        }
    }
    return minLength == n + 1 ? 0 : minLength;
}

// approach 2 two pointer O(n)
int smallestSubWithSumII(int arr[], int n, int x)
{
    int minLength = n+1;
    int start = 0;
    int end = 0;
    int currsum = 0;
    while(end < n)
    {
        
        while(currsum<=x && end<n)
        {
            currsum+=arr[end];
            end++;
        }
        while(currsum > x && start < n)
        {
            if(end-start < minLength)
            minLength = end -start;
            currsum-=arr[start];
            start++;
        }
    }
    return minLength == n + 1 ? 0 : minLength;
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
    cout << "Enter the value of k";
    int k;
    cin >> k;

    cout << smallestSubWithSumII(arr, n, k) << endl;
    cout << smallestSubWithSumII(arr, n, k) << endl;
    return 0;
}
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// Given an array of positive integers. 
//We need to make the given array a ‘Palindrome’. 
//The only allowed operation is”merging” (of two adjacent elements). 
//Merging two adjacent elements means replacing them with their sum. 
//The task is to find the minimum number of merge operations 
//required to make the given array a ‘Palindrome’.


int operations(int arr[] ,int n)
{
    int i = 0;
    int j = n-1;
    int ans = 0;
    while(i<=j)
    {
        if(arr[i] == arr[j])
        {
            i++;
            j--;
        }
        else if(arr[i]>arr[j])
        {
            j--;
            arr[j] +=arr[j+1];
            ans++;
        }
        else if(arr[i]<arr[j])
        {
            i++;
            arr[i]+=arr[i-1];
            ans++;
        }
    }
    return ans;
}
int minMergeOperations(vector<int> arr)
{
    int n = arr.size();
    vector<vector<int> > dp(n, vector<int>(n, 0));
 
    // Fill the dp table
    for (int gap = 1; gap < n; gap++) {
        for (int i = 0; i < n - gap; i++) {
            int j = i + gap;
            if (arr[i] == arr[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            }
            else {
                dp[i][j]
                    = min(dp[i][j - 1], dp[i + 1][j]) + 1;
            }
        }
    }
 
    return dp[0][n - 1];
}
int main()
{
    
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Given an array of positive integers. 
//Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, 
//the consecutive numbers can be in any order.
// Example 1:
// Input:
// N = 7
// a[] = {2,6,1,9,4,5,3}
// Output:
// 6

class Solution{
public:

//approach 1 //brute force//sorting//O(nlogn)
int longestConsecutiveSubsequenceI(int arr[],int n)
{
    sort(arr,arr+n);
    int count = 1;
    int ans = INT_MIN;
    for(int i=1;i<n;i++)
    {
        if(arr[i] == arr[i-1])
        continue;
        if(arr[i] == arr[i-1]+1)
        count++;
        else{
            ans = max(ans,count);
            count = 1;
        }
         ans = max(ans,count);
    }
    return ans;
}
//approach 2 using frequency count array O(n)
int longestConsecutiveSubsequenceII(int arr[],int n)
{
    int temp[1000001] = {0};
    int maximum = -1;
    int count = 0;
    int ans = INT_MIN;
    for(int i=0;i<n;i++)
    {
        temp[arr[i]]++;
        maximum = max(maximum,arr[i]);
    }
    for(int i=0;i<=maximum;i++)
    {
        if(temp[i] >=1 )
        {
            count++;
        }
        else{
            ans = max(ans,count);
            count = 0;
        }
        ans = max(ans,count);//for the case when we never entered into the else case//01112
    }
    return ans;
    
}
//approach 2 using set O(n)
int longestConsecutiveSubsequenceIII(int arr[],int n)
{
    unordered_set<int>s;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(s.find(arr[i]-1) != s.end())
        continue;
        else{
            int j = arr[i];
            while(s.find(j) != s.end())
            j++;
            ans = max(ans,j-arr[i]);
        }
    }
    return ans;
}
};
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
    Solution s;
    cout<<s.longestConsecutiveSubsequenceI(arr,n)<<endl;
    cout<<s.longestConsecutiveSubsequenceII(arr,n)<<endl; 
    cout<<s.longestConsecutiveSubsequenceIII(arr,n)<<endl; 
    return 0;

}
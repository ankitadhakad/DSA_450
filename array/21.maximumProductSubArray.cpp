#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// {
// Given an array Arr[] that contains N integers (may be positive, negative or zero).
// Find the product of the maximum product subarray.
// Example 1:
// Input:
// N = 5
// Arr[] = {6, -3, -10, 0, 2}
// Output: 180
// }

// approach 1 O(n^3)
int maxSubI(vector<int> &v, int n)
{
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int product = 1;
            for (int k = i; k < j; k++)
            {
                product *= v[k];
            }
            ans = max(ans, product);
        }
    }
    return ans;
}
// approach 2 O(n^2)
int maxSubII(vector<int> &v, int n)
{
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int product = 1;
        for (int j = i; j < n; j++)
        {
            product *= v[j];
            ans = max(ans, product);
        }
    }
}
// approach 3 O(n)
int maxSubIII(vector<int> &nums)
{
    int prod = 1;
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        prod *= nums[i];
        maxi = max(prod, maxi);
        if (prod == 0)
            prod = 1;
    }
    prod = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        prod *= nums[i];
        maxi = max(prod, maxi);
        if (prod == 0)
            prod = 1;
    }
    return maxi;
}
// approach 4 O(n)//single pass
int maxSubIV(vector<int> &nums)
{
    int prefix = 1;
    int suffix = 1;
    int ans = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (prefix < 0)
            prefix = 1;
        if (suffix < 0)
            suffix = 1;
        prefix = prefix * nums[i];
        suffix = suffix * nums[n - i - 1];

        ans = max(ans, max(prefix, suffix));
    }
    return ans;
}
// approach 5 Kadane's//can't understand
int maxSubV(vector<int> &nums)
{
    int maxProd = nums[0];
    int currMax = nums[0];
    int currMin = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < 0)
            swap(currMax, currMin);
        currMax = max(nums[i], currMax * nums[i]);
        currMin = min(nums[i], currMin * nums[i]);
        maxProd = max(maxProd, currMax);
    }
    return maxProd;
}
int main()
{
     int n = 0;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the element"<<endl;
        cin>>v[i];
    }

    for(int i=0; i<n; i++)
    {
        cout<<v[i];
    }
    cout<<endl;

    return 0;
}
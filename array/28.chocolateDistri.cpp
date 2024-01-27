#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach 1 recursion//O(nlogn+2^n)
long long f(vector<long long> a, long long l, long long r, long long &ans, long long m)
{
    if (l >= r)
        return LONG_MAX;
    if (r - l + 1 < m)
        return LONG_MAX;
    ans = min(ans, a[r] - a[l]); // Update ans with the current minimum difference
    f(a, l + 1, r, ans, m);
    f(a, l, r - 1, ans, m);
    return a[r] - a[l];
}
long long findMinDiffI(vector<long long> a, long long n, long long m)
{
    // code
    long long ans = LONG_MAX;
    sort(a.begin(), a.end());
    ans = a[n - 1] - a[0];
    f(a, 0, n - 1, ans, m);
    return ans;
}
// approach 2 sliding window//O(nlogn)
long long findMinDiffII(vector<long long> a, long long n, long long m)
{

    // Sort the given packets
    sort(a.begin(), a.end());

    long long start = 0, end = 0;
    // Largest number of chocolates
    long long mind = LONG_LONG_MAX;

    // Find the subarray of size m such that
    // difference between last (maximum in case
    // of sorted) and first (minimum in case of
    // sorted) elements of subarray is minimum.
    for (long long i = 0; i + m - 1 < n; i++)
    {
        long long diff = a[i + m - 1] - a[i];
        if (mind > diff)
        {
            mind = diff;
            start = i;
            end = i + m - 1;
        }
    }
    return a[end] - a[start];
}

//O(n^loution using two loops)
long long findMinDiffIII(vector<long long>a,long long n,long m)
{
    sort(a.begin(),a.end());
    int ans = INT_MAX;
    for(long long i=0;i+m-1<n;i++)
    {
        for(int j = i+m-1;j<n;j++)
        {
            if(a[j]-a[i] < ans)
            ans = a[j]-a[i];
        }
    }
    return ans;
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
    return 0;
}
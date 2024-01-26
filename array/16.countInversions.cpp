#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//{ Given an array of integers. Find the Inversion Count in the array.
// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted.
// If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum.
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
//}

;
// approach1//brute force//O(N^2)
int count(vector<int> v, int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[j] > v[i])
                ans++;
        }
    }
    return ans;
}
// approach 2//mergeSort//O(NlogN),space->O(N)
class Solution
{
    long long my_counter = 0;
    void merge(long long a[], long long low, long long high, long long mid)
    {
        long long l1 = mid - low + 1;
        long long l2 = high - mid;
        long long a1[l1];
        long long a2[l2];
        for (long long i = 0; i < l1; i++)
        {
            a1[i] = a[i + low];
        }
        for (long long i = 0; i < l2; i++)
        {
            a2[i] = a[mid + i + 1];
        }
        long long left = 0;
        long long right = 0;
        long long k = low;
        while (left < l1 && right < l2)
        {
            if (a1[left] <= a2[right])
            {
                a[k] = a1[left];
                left++;
            }
            else
            {
                a[k] = a2[right];
                right++;
                my_counter += l1 - left;
            }
            k++;
        }
        while (left < l1)
        {
            a[k++] = a1[left++];
        }

        while (right < l2)
        {

            a[k++] = a2[right++];
        }
    }
    void mergeSort(long long arr[], long long low, long long high)
    {
        if (low < high)
        {
            long long mid = low + (high - low) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, high, mid);
        }
    }

public:
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr, 0, N - 1);
        long long int res = my_counter;
        my_counter = 0;
        // returning the count of inversions in the array.
        return res;
    }
};

int main()
{
    int n = 0;
    cout << "Enter the size of array" << endl;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element" << endl;
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    long long arr[] = {2, 4, 1, 3, 5};
    Solution s;
    cout << s.inversionCount(arr, 4);
    return 0;
}
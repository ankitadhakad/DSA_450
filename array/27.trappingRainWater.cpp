#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// approach 1 Brute Force O(N^2)
int trappingRainWaterI(int arr[], int n)
{
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int left = arr[i];
        for (int j = 0; j < i; j++)
        {
            left = max(arr[j], left);
        }
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            right = max(arr[j], right);
        }
        ans += min(right, left) - arr[i];
    }
    return ans;
}

// approach 2 O(N)//two pass//space -> O(N)
// using prefix and suffix array
int trappingRainWaterII(int arr[], int n)
{
    int prefix[n];
    int suffix[n];
    prefix[0] = arr[0];
    suffix[n-1] = arr[n-1];
    int water = 0;
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], arr[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        water += min(suffix[i], prefix[i]) - arr[i];
    }
    return water;
}
// approach 3 O(n) //single pass//space optimized//two pointer
int trappingRainWaterIII(int arr[], int n)
{
    int left = 0;
    int right = n - 1;
    int leftMax = INT_MIN;
    int rightMax = INT_MIN;
    int water = 0;
    while (left <= right)
    {
        if (arr[left] <= arr[right])
        {
            if (arr[left] >= leftMax)
                leftMax = arr[left];
            else
                water += leftMax - arr[left];
            left++;
        }

        else
        {
            if (arr[right] >= rightMax)
                rightMax = arr[right];
            else
                water += rightMax - arr[right];
            right--;
        }
    }
    return water;
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

    cout << trappingRainWaterI(arr, n) << endl;
    cout << trappingRainWaterII(arr, n) << endl;
    cout << trappingRainWaterIII(arr, n) << endl;
    return 0;
}
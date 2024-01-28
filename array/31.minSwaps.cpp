#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// sliding window O(n)
int minSwap(int arr[], int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            count++;
    }
    int swap = 0;

    for (int i = 0; i < count; i++)
    {
        if (arr[i] > k)
        {
            swap++;
        }
    }
    int i = 0;
    int j = count;
    int ans = swap;
    while (j < n)
    {
        if (arr[i] > k)
            swap--;
        if (arr[j] > k)
            swap++;
        ans = min(ans, swap);
        i++;
        j++;
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
    cout << "Enter value of k";
    cin >> k;

    cout << minSwap(arr1, n, k);
    return 0;
}
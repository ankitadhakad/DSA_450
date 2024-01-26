#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach 1 O(n^2)

bool subArrayExists(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int currentSum = arr[i];
        if (currentSum == 0)
        {
            return true;
        }
        else
        {
            // Try all subarrays starting with 'i'
            for (int j = i + 1; j < n; j++)
            {
                currentSum += arr[j];

                if (currentSum == 0)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
// approach 2
bool subArray(int arr[], int n)
{
    // Your code here
    unordered_map<int, int> m;
    long long sum = 0;
    m[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] == 0 || m.find(sum) != m.end())
            return true;
        m[sum]++;
    }
    return false;
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
    bool ans1 = subArray(arr,n);
    cout<<ans1;
    cout<<endl;
    bool ans2 = subArrayExists(arr,n);
    cout<<ans2;


    return 0;
}
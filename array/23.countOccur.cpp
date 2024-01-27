#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach 1->Brute force approach O(n^2)
int countOccurI(int arr[], int n, int k)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
            continue;
        int curr = arr[i];
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == curr)
            {
                count++;
                arr[j] = -1;
            }
        }
        if (count > n / k)
            ans++;
    }
    return ans;
}

// approach 2 using map
int countOccurII(int arr[], int n, int k)//O(n)
{
    unordered_map<int, int> mp;
    int a = n / k;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto it : mp)
{
    cout << "Element: " << it.first << ", Count: " << it.second << endl;
}
    int count = 0;
    for (auto it : mp)
    {
        if (it.second > a)
        {
            count++;
        }
    }
    return count;
}

//approach 3
// The idea is to apply Moore’s Voting algorithm, 
// as there can be at max k – 1 elements present in the array 
// which appears more than n/k times so their will be k – 1 candidates. 
// When we encounter an element which is one of our candidates then increment the count 
// else decrement the count.)(N*K)
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

    int m = 0;

    cout << "Enter Size Of the Array" << endl;
    cin >> m;
    int arr2[m];
    cout << "Enter elements of Array" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    cout << endl;
    print(arr2, m);
    cout << endl;

    int k = 0;
    cout << "Enter The value of k" << endl;
    cin >> k;
    cout << countOccurI(arr1, n, k) << endl;
    cout << countOccurII(arr2, m, k) << endl;
    return 0;
}
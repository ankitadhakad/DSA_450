#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. 
//Task is to check whether a2[] is a subset of a1[] or not. 
//Both the arrays can be sorted or unsorted. 
//There can be duplicate elements.
// Example 1:
// Input:
// a1[] = {11, 7, 1, 13, 21, 3, 7, 3}
// a2[] = {11, 3, 7, 1, 7}
// Output:
// Yes


//approach 1 Brute Force O(nlogn+mlogm)
string isSubsetI(int a1[], int a2[], int n, int m) {
    sort(a1,a1+n);
    sort(a2,a2+m);

    int i = 0, j = 0;

    while (i < n && j < m) {
        if (a1[i] < a2[j]) {
            ++i;
        } else if (a1[i] == a2[j]) {
            ++i;
            ++j;
        } else {
            return "No";
        }
    }

    return (j == m) ? "Yes" : "No";
}

//approach2 using map O(M+n)
string isSubsetII(int a1[], int a2[], int n,int m)
{
    unordered_map<int,int>mp1,mp2;
    for(int i=0;i<n;i++)
    {
        mp1[a1[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        mp2[a2[i]]++;
    }
    int count = 0;
    for(auto it:mp2)
    {
        if(mp1[it.first] >= it.second)
        count++;
    }
      if (count == m)
        return "Yes";
    else
        return "No";
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


    cout<<isSubsetI(arr1,arr2,n,m)<<endl;
    cout<<isSubsetII(arr1,arr2,n,m);
    return 0;
}
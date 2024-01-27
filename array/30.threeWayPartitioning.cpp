#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Given an array of size n and a range [a, b].
// The task is to partition the array around the range such that array is divided into three parts.
// 1) All elements smaller than a come first.
// 2) All elements in range a to b come next.
// 3) All elements greater than b appear in the end.
// The individual elements of three sets can appear in any order.
// You are required to return the modified array.

// approach 1 using three different data structures for them
// approach 2 simply sorting the array
// as: a<b and elements<a => elements<b array={elements<a,b| elements>a and elements<b| elements>b}
// approach 3//two pointer O(N)
void threeWayPartition(vector<int> &arr, int a, int b, int n)
{
    int end = n - 1;
    int start = 0;
    int i = 0;
    while (i<=end)
    {
        if(arr[i] < a)
        {
            swap(arr[i],arr[start]);
            start++;
            i++;
        }
        else if(arr[i] > b)
        {
            swap(arr[i],arr[end]);
            end--;
            i++;
        }
        else i++;
    }
}
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
    int a,b;
    cout<<"Enter the  range"<<endl;
    cin>>a>>b;
    threeWayPartition(v,a,b,n);
     for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
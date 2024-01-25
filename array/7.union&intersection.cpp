#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// {
//     Given two arrays a[] and b[] of size n and m respectively.
// The task is to find the number of elements in the union between these two arrays.
// Union of the two arrays can be defined as the set containing distinct elements from both the arrays.
// If there are repetitions, then only one occurrence of element should be printed in the union.
// Note : Elements are not necessarily distinct.
// }

int doUnion(int a[], int n, int b[], int m)//O((m+n)log(m+n))
{
   
    // using set to store the elements.
    unordered_set<int> s;

    // we insert all the elements of first array in set.
    for (int i = 0; i < n; i++)
        s.insert(a[i]);

    // we insert all the elements of second array in set.
    // Set does not contain duplicates.
    for (int i = 0; i < m; i++)
        s.insert(b[i]);

    // returning the size of set which is total number of elements in set.
    return s.size();
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


    int uni = doUnion(arr1,n,arr2,m); 

    cout<<uni;
    return 0;
}
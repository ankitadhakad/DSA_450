#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// approach 1
// use separate array.... store elements of both arrays and then sort the the resultant array

// approach 2
void merge(int ar1[], int ar2[], int m, int n) // O(m*n)
{
    // Iterate through all elements
    // of ar2[] starting from the last element
    for (int i = n - 1; i >= 0; i--)
    {
        // Find the smallest element greater than ar2[i].
        // Move all elements one position ahead till the
        // smallest greater element is not found */
        int j, last = ar1[m - 1];
        for (j = m - 2; j >= 0 && ar1[j] > ar2[i]; j--)
            ar1[j + 1] = ar1[j];

        // If there was a greater element
        if (last > ar2[i])
        {
            ar1[j + 1] = ar2[i];
            ar2[i] = last;
        }
    }
}

// approach 3 O((m+n)*log(m+n))
void merge(long long arr1[], long long arr2[], int n, int m)
{
    // code here
    int i = n - 1;
    int j = 0;
    while (i >= 0 && j < m)
    {
        if (arr1[i] > arr2[j])
        { // if last element of arr1 is smaller than first element of second array
            // then we can say both arrays when placed in order are already sorted so simply break the loop
            swap(arr1[i], arr2[j]);
            i--;
            j++;
        }
        else
            break;
    }
    sort(arr1, arr1 + n); 
    sort(arr2, arr2 + m);
}


//approach 4 O(m+n)//Euclidian most efficient
// {
//     Merge the two arrays as we do in merge sort, while simultaneously using Euclidean Division Lemma, i.e. (((Operation on the array) % x) * x)
// After merging divide both arrays with x
// Where x needs to be a number greater than all elements of the array
// Here in this case x, (according to the constraints) can be 10e7 + 1
// }
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
    return 0;
}
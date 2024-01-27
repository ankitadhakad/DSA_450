#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//approach 1 O(n^3)
bool find3NumbersI(int A[], int n, int X)
    {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (A[i] + A[j] + A[k] == X) {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
     //O(N^2)
    bool find3NumbersII(int A[], int n, int X)
    {
        for (int i = 0; i < n - 2; i++) 
        {
            // Find pair in subarray A[i+1..n-1]
            // with sum equal to sum - A[i]
            unordered_set<int> s;
            int curr_sum = X - A[i];
            for (int j = i + 1; j < n; j++) 
            {
                if (s.find(curr_sum - A[j]) != s.end()) 
                {
                    return true;
                }
                s.insert(A[j]);
            }
        }
    
        // If we reach here, then no triplet was found
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
    cout << "Enter The value of k" << endl;
    cin >> k;
    cout<<find3NumbersI(arr1,n,k)<<endl;
    cout<<find3NumbersII(arr1,n,k)<<endl;
    return 0;
}
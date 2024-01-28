#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// There are 2 sorted arrays A and B of size n each.
// Write an algorithm to find the median of the array obtained after
// merging the above 2 arrays(i.e. array of length 2n).

// approach 1 //O(nlogn)
// store all elements in new array and sort it to find median

// approach 2 O(n)
// keep track of median from both the arrays
double getMedianI(int arr1[], int arr2[], int n)
{
    int m1 = -1;
    int m2 = -1;
    int i = 0;
    int j = 0;
    int count = 0; // to keep track of number of elements
    while (count <= n)
    {
        if (i == n) // all elements of arr1 are smaller than the first element of arr2
        {
            m1 = m2;
            m2 = arr2[0];
            break;
        }

        if (j == n) // all elements of arr2 are smaller than the first elements of arr1
        {
            m1 = m2;
            m2 = arr1[0];
            break;
        }
        if (arr1[i] <= arr2[j])
        {
            m1 = m2;
            m2 = arr1[i];
            i++;
        }
        else
        {
            m1 = m2;
            m2 = arr2[j];
            j++;
        }
        count++;
    }
    return 1.0 * (m1 + m2) / 2;
}


//approach 3 O(logn)//using binary search
//same approach for arrays with different sizes
int main()
{

    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};

    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is " << getMedianI(ar1, ar2, n1);
    else
        cout << "Doesn't work for arrays"
             << " of unequal size";

    return 0;
}
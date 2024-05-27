#include "bits/stdc++.h"
using namespace std;
 
/* prints element and NSE pair 
for all elements of arr[] of size n */
///O(N^2)
void printNSE(int arr[], int n)
{
    int next, i, j;
    for (i = 0; i < n; i++)
    {
        next = -1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                next = arr[j];
                break;
            }
        }
        cout << arr[i] << " --> "
             << next << endl;
    }
}
 //O(N)
vector<int> findNextSmallerElement(const std::vector<int>& arr) {
   
  // declaring vector for storing next smaller element
    vector<int> result(arr.size(), -1);  
 
  // declaring a stack
    stack<int> st;  
 
  // iterating through array 
    for (int i = 0; i < arr.size(); ++i) {
       
      // checking for next smaller element
        while (!st.empty() && arr[i] < arr[st.top()]) {
           
          // pushing the next smaller element
            result[st.top()] = arr[i];
           
            st.pop();
        }
 
        // pushing elements of array in stack
        st.push(i);
    }
 
    return result;
}
int main()
{
    int arr[]= {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNSE(arr, n);
    return 0;
}
 
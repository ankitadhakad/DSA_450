#include<iostream>
#include <stack>
using namespace std;


// // Given an array arr[ ] of size N having elements, 
// the task is to find the next greater element 
// for each element of the array in order of their appearance in the array.
// // Next greater element of an element in the array is the nearest element 
// on the right which is greater than the current element.
// // If there does not exist next greater of current element, 
// then next greater element for current element is -1. 
// For example, next greater of the last element is always -1.

// Example 1:

// Input: 
// N = 4, arr[] = [1 3 2 4]
// Output:
// 3 4 4 -1
// Explanation:
// In the array, the next larger element 
// to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
// since it doesn't exist, it is -1.


//approach 1 using two nested loops //O(n^2)


//approach 2 using stack
void nextGreater(int arr[],int n)
{
    int ans[n];
    for(int i=0;i<n;i++)
    {
        ans[i]= -1;
    }
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && arr[i] > arr[s.top()])
        {
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}
int main()
{ int arr[] = {1,3,2,4};
nextGreater(arr,4);

    return 0;
}

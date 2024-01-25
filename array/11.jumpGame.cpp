#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//brute force O(2^n)
//dp solution ->O(n^2)
int minJumpsBruteForce(int arr[], int index,int n) {
    // Base case: if at the end of the array, no more jumps needed
    if (index == n- 1) {
        return 0;
    }

    // Initialize the minimum jumps to a large value
    int minJumps = INT_MAX;

    // Try all possible jumps from the current position
    for (int i = 1; i <= arr[index]; ++i) {
        if (index + i < n) {
            // Recursively calculate the minimum jumps from the next position
            int jumpsFromNext = minJumpsBruteForce(arr, index + i);

            // If the current jump leads to a valid path, update the minimum jumps
            if (jumpsFromNext != INT_MAX) {
                minJumps = min(minJumps, 1 + jumpsFromNext);
            }
        }
    }

    return minJumps;
}
//greedy solution O(n)
int minJumps(int arr[],int n)
{
   
   int farthest = 0;
   int curr = 0;
   int jump = 0;
   for(int i=0; i<n; i++)
   {
      farthest = max(farthest,arr[i]+i);
      if(i==curr)
      {
        jump++;
        curr = farthest;
      }

   }
   if(curr<n)
   return -1;
   else return jump;
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
    cout<<minJumps(arr1,n)<<endl;
    return 0;
}
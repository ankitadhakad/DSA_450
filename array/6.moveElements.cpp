#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//{
    //An array contains both positive and negative numbers in random order.
// Rearrange the array elements so that all negative numbers appear before all positive numbers.
// Examples : 
// Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
// Output: -12 -13 -5 -7 -3 -6 11 6 5
//}

//approach 1
//sort the array(if relative order of each number does not matter)

//approach2 
//store +ve into one data structure and -ve in another then store them in single data structure


//approach 3
//quick select
//The idea is to simply apply the partition process of quicksort. 

void rearrange(int arr[], int n) 
{ 
    int j = 0; 
    for (int i = 0; i < n; i++) { 
        if (arr[i] < 0) { 
            if (i != j) 
                swap(arr[i], arr[j]); 
            j++; 
        } 
    } 
} 


//approach4
//two-pointers
void reArrange(int arr[],int n){ 
      int low =0,high = n-1; 
      while(low<high){ 
      if(arr[low]<0){ 
          low++; 
      }else if(arr[high]>0){ 
          high--; 
      }else{ 
        swap(arr[low],arr[high]); 
      } 
    } 
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
    int arr[n];
    cout << "Enter elements of Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    print(arr, n);
    cout << endl;
    rearrange(arr,n);
    print(arr,n);
    cout<<endl;
    reArrange(arr,n);
    print(arr,n);
    return 0;
}
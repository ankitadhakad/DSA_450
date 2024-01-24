#include <iostream>
using namespace std;
void reverse(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)   
    {
        swap(arr[i], arr[n - i - 1]);
    }
}
//using separate array can also be done
//Recursive:
void rvereseArray(int arr[], int start, int end) 
{ 
    if (start >= end) 
    return; 
      
    int temp = arr[start];  
    arr[start] = arr[end]; 
    arr[end] = temp; 
      
    // Recursive Function calling 
    rvereseArray(arr, start + 1, end - 1);  
} 
int main()
{
    //    Reverse the array

    int n = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    reverse(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
#include <iostream>

#include <limits.h>

using namespace std;
int max(int arr[],int n)
{
    int maxi = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=maxi)
        maxi=arr[i];
    }
    return maxi;
}
int min(int arr[],int n)
{
    int mini = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=mini)
        mini=arr[i];
    }
    return mini;
}
int main()
{
    int n = 0;

    cout<<"Enter Size Of the Array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter elements of Array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int maxm = max(arr,n);
    cout<<"maxi: "<<maxm<<endl;
    int minm =min(arr,n);
    cout<<"mini: "<<minm<<endl;
    return 0;

}
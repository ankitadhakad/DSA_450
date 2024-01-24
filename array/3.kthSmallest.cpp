#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void print(int arr[],int n)
{
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
 //bruteforce
int kthSmallest(int arr[],int k,int n)
{
    sort(arr,arr+n);//O(nlogn)
    return arr[k-1];
}

//using heap;
int kthSmallestheap(int arr[],unsigned k,int n)
{
    priority_queue<int>pq;//O(nlogk)
    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
         if(pq.size()>0 && pq.size()>k)
          pq.pop();
    }
   
    return pq.top();
}

//optimized//Expected


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
    print(arr,n);
    cout<<endl;
    cout<<"Enter the value of k";
    unsigned k;
    cin>>k;
     int kthSmallestnum = kthSmallestheap(arr,k,n);
     cout<<kthSmallestnum<<endl;



    return 0;
}
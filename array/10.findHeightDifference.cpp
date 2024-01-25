#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//brute force
 int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int min_diff=arr[n-1]-arr[0];
        int temp_min=arr[0];
        int temp_max=arr[n-1];
        for(int i=1;i<n;i++)
        {
            // if(arr[i]-k <0)
            // continue;
            temp_min=min(arr[0]+k,arr[i]-k);
            temp_max=max(arr[i-1]+k,arr[n-1]-k);
            min_diff=min(min_diff,temp_max-temp_min);
        }
        return min_diff;
 }
//optimized
int minHeightDiff(int arr[],int n,int k)
{
    vector<pair<int,int>>v;
    vector<int>taken(n);
    for(int i=0;i<n;i++)
    {
        v.push_back({arr[i]+k,i});
        v.push_back({arr[i]-k,i});
    }

    sort(v.begin(),v.end());
    int ans = 0;
    int left = 0;
    int right = 0;
    int totalElements = 0;
    while(right<v.size() && totalElements<n)
    {
        if(taken[v[right].second] == 0){
            totalElements++;
        }
        taken[v[right].second]++;
        right++;

    }
    ans = v[right-1].first - v[left].first;

    while(right <v.size())
    {

        if(taken[v[left].second] == 1)
        {
            totalElements--;
        }
        taken[v[left].second]--;
        left++;
        while(totalElements<n && right<n)
        {
             if(taken[v[right].second] == 0){
            totalElements++;
        }
        taken[v[right].second]++;
        right++;
        }
        if(totalElements == n)
        ans = min(ans,v[right-1].first-v[left].first);
        else break;
    }
    return ans;
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
    int k=0;
    cout<<"Enter value of k";
    cin>>k;
    cout<<minHeightDiff(arr1,n,k)<<endl;
    cout<<getMinDiff(arr1,n,k)<<endl;
    return 0;
}
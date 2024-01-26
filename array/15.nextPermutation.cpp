#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//approach 1 O(N*N!)
//generate all permutation //sort them
//liner serach for the current arrray//retrun array of index+1
void permute(vector<int>&a, int l, int r,vector<vector<int>>&ans) 
{ 
    // Base case 
    if (l == r) 
        ans.push_back(a); 
    else { 
        // Permutations made 
        for (int i = l; i <= r; i++) { 
  
            // Swapping done 
            swap(a[l], a[i]); 
  
            // Recursion called 
            permute(a, l + 1, r,ans); 
  
            // backtrack 
            swap(a[l], a[i]); 
        } 
    } 
}

//approach 2
//stl next_permutation()

//approach 3

void nextPermutation(vector<int>&v)//O(N)
{
    int index = -1;
     int n =v.size();
     for(int i=n-2;i>=0;i--)
     {
        if(v[i]<v[i+1])
        {
            index = i;
            break;//breakpoint
        }
     }
     if(index == -1)
     {
        reverse(v.begin(),v.end());
        return;
     }
     for(int i=n-1;i>=0;i--)
     {
        if(v[i]>v[index])
        {
            swap(v[index],v[i]);
            break;
        }
     }
     reverse(v.begin()+index+1,v.end());
}
int main()
{

    int n = 0;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the element"<<endl;
        cin>>v[i];
    }

    for(int i=0; i<n; i++)
    {
        cout<<v[i];
    }
    cout<<endl;
    
    vector<vector<int>>permutation;
    permute(v,0,n-1,permutation);
    int m = permutation.size();
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<permutation[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    nextPermutation(v);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;

}
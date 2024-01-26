#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//approach 1->using 3 set

//approach 2->threepointers 
 vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)

        {
            //code here.
            vector<int>result;
            int last = INT_MIN;
            int i=0,j=0,k=0;
            while(i<n1 &&j<n2&&k<n3)
            {
                if(A[i] == B[j] && A[i] == C[k] && last !=A[i])
               {
                   result.push_back(A[i]);
                   last = A[i];
                   i++;
                   j++;
                   k++;
               }
               else if(min({A[i],B[j],C[k]}) == A[i])
               i++;
               else if(min({A[i],B[j],C[k]}) == B[j])
               j++;
               else k++;
            }
            return result;
        }
        int main()
        {
            return 0;
        }
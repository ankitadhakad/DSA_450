#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// Given an array A[] of size N and a positive integer K, 
// find the first negative integer for each and every window(contiguous subarray) of size K.

// Example 1:

// Input : 
// N = 5
// A[] = {-8, 2, 3, -6, 10}
// K = 2
// Output : 
// -8 0 -6 -6
// Explanation :
// First negative integer for each window of size k
// {-8, 2} = -8
// {2, 3} = 0 (does not contain a negative integer)
// {3, -6} = -6
// {-6, 10} = -6

//brute force O(N*K)
vector<long long> printFirstNegativeIntegerI(long long int A[],
                                             long long int N, long long int K) {
        vector<long long> result;

        for (long long i = 0; i <= N - K; i++) {
            long long j;
            bool found = false;
    
            for (j = i; j < i + K; j++) {
                if (A[j] < 0) {
                    result.push_back(A[j]);
                    found = true;
                    break;
                }
            }
    
            if (!found) {
                result.push_back(0);
            }
        }
    
        return result;                                         
 }


//optimized using queue O(N)
vector<long long> printFirstNegativeIntegerII(long long int A[],
                                             long long int N, long long int K)
{
    
    vector<long long>ans;
    queue<long long int>q;
    int i=0;
    int j=0;
    while(j<N)
    {
        if(A[j] < 0)
        q.push(A[j]);
        if(j-i+1<K)
        j++;
        else{
            if(q.empty())
            ans.push_back(0);
            else ans.push_back(q.front());
            if(A[i] == q.front())
            q.pop();
            i++;
            j++;
        }
        
    }
    return ans;
    
                                                 
 }
int main()
{
    return 0;
}
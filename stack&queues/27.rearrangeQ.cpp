#include <iostream>
#include<vector>
#include<queue>
using namespace std;

// You are given a queue Q of N integers of even length, 
// rearrange the elements by interleaving the first half of the queue 
// with the second half of the queue.
// Example 1:
// Input:
// N = 4
// Q = {2,4,3,1}
// Output:
// {2,3,4,1}
// Explanation:
// After the mentioned rearrangement of the first half
// and second half, our final queue will be {2,3,4,1}.

/// can also be done using separate queue or stack
 vector<int> rearrangeQueue(queue<int> &q)
    {
        int n =  q.size();
        vector<int>ans(n,0);
        int i = 0;
        while(q.size()>=n/2 && i <n )
        {
            ans[i] = q.front();
            q.pop();
            i+=2;
        }
        i = 1;
         while(q.size() && i <n )
        {
            ans[i] = q.front();
            q.pop();
            i+=2;
        }
        return ans;
    }
int main()
{
    return 0;
}
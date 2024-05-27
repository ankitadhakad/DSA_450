#include<iostream>
#include<stack>
#include<queue>
using namespace std;
 void reverseQ(queue<int> &q, int k) {
        if (k == 0) return;
        
        int x = q.front();
        q.pop();
        
        reverseQ(q, k - 1);
        
        q.push(x);
    }
//TC -O(N);//recursive stack space O(K)

    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        int s = q.size();
        
        reverseQ(q, k);
        
        for (int i = 1; i <= s - k; i++) {
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
    //approach 2 using another data structure
int main()
{
    return 0;
}
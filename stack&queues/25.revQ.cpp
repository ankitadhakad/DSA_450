#include<iostream>
#include<stack>
#include <queue>

//approach 1 using stack tc->O(N)
  queue<int> revI(queue<int> q)
    {
        //using a stack to reverse the queue.
        stack<int> s;      
        while(!q.empty())
        {
            //pushing elements from queue into stack and removing them from queue.
            s.push(q.front());       
            q.pop();                 
        }
        //creating new queue.
        queue<int> a;
        while(!s.empty())
        {
            //now pushing elements back into the queue from stack and removing them 
            //from stack. queue gets reversed as stack follows last in first out.
            a.push(s.top());         
            s.pop();                
        }
        //returning reversed queue.
        return a;
    }
    //approach 2 using recursion tc -O(N^2)
     void reverseQueue(queue<int>& q)
{
    // base case
    if (q.size() == 0)
        return ;
 
    int fr = q.front();
    q.pop();

    reverseQueue(q);
    q.push(fr);
}
    queue<int> revII(queue<int> q)
    {
          reverseQueue(q);
     return q;
    }
int main()
{
    return 0;
}
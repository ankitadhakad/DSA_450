#include<iostream>
#include<stack>
using namespace std;

// Given a stack S and an integer N, 
// the task is to insert N at the bottom of the stack.

//approach 1 using separate data structure

//approach 2 recursion
stack<int> insert(stack<int> S, int N)
{
    // If stack is empty
    if (S.empty())
        S.push(N);
 
    else {
 
        // Stores the top element
        int X = S.top();
 
        // Pop the top element
        S.pop();
 
        // Recurse with remaining elements
        S = insert(S, N);
 
        // Push the previous
        // top element again
        S.push(X);
    }
    return S;
}
 
int main()
{
    stack<int>s;
    s.push(8);
    s.push(9);
    insert(s,10);
    return 0;
}
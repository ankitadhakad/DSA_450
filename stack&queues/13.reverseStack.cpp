#include<iostream>
#include<stack>
using namespace std;
//approach 1 using another stack

//approach 2
void insert(stack<int>& S, int N)
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
         insert(S, N);
 
        // Push the previous
        // top element again
        S.push(X);
    }
    
}


void reverse(stack<int>&st)
{
     if (st.size() > 0) {
 
        // Hold all items in Function
        // Call Stack until we
        // reach end of the stack
        int x = st.top();
        st.pop();
        reverse(st);
 
        // Insert all the items held
        // in Function Call Stack
        // one by one from the bottom
        // to top. Every item is
        // inserted at the bottom
        insert(st, x);
    }
    return;
}
int main()
{
    stack<int>s;
    s.push(8);
    s.push(9);
    reverse(s);
    return 0;
}
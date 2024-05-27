#include<iostream>
#include<stack>
using namespace std;
// Given a stack, the task is to sort it such that the 
// top of the stack has the greatest element.
// Example 1:
// Input:
// Stack: 3 2 1
// Output: 3 2 1
// Example 2:
// Input:
// Stack: 11 2 32 3 41
// Output: 41 32 11 3 2

void sortedInsert(stack<int>&s,int n)
{
    if(s.empty() || s.top()<n)
    {
        s.push(n);
        return;
    }
    int temp = s.top();
    s.pop();
    sortedInsert(s,n);
    s.push(temp);
}
void sort(stack<int>&s)
{
    if(!s.empty())
    {

    
    int temp = s.top();
    s.pop();
    sort(s);
    sortedInsert(s,temp);
    }
}
int main()
{

    return 0;
}
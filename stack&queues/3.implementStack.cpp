#include <iostream>
using namespace std;
class Stack
{
    
    public:
    int *arr;
    int top;
    int cap;
    Stack(int n)
    {
        cap = n;
        arr = new int[cap];
        top = -1;

    }
    void push(int x)
    {
        if(top == cap-1)
        cout<<"stack is full"<<endl;
        else
        {
            top++;
            arr[top] = x;
        }
    }
    int pop()
    {
        if(top == -1)
        cout<<"stack is empty"<<endl;
        int res = arr[top];
        top--;
        return res;
    }
    int peak()
    {
        if(top == -1)
        cout<<"stack is empty"<<endl;
        return arr[top];
    }
    int size()
    {
        return top+1;
    }
    bool isempty()
    {
        top==-1?true:false;
    }
    bool isfull()
    {
        top+1==cap?true:false;
    }

};
int main()
{
    Stack s(5);
    s.pop();
    // s.push(10);
    // s.push(9);
    // s.push(8);
    // s.push(7);
    // s.push(6);
    // s.push(6);
    
    return 0;
}
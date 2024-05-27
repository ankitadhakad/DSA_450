#include <iostream>
using namespace std;
class Queue
{
   public:
   int cap;
   int top;
   int *arr;
   Queue(int n)
   {
    cap = n;
    arr = new int[cap];
    top = -1;
   }
   void push(int x)
   {
    if(top+1 == cap)
    cout<<"queue is full"<<endl;
    else
    {
        top++;
        arr[top] = x;
    }
   }
   void pop()
   {
    if(top==-1)
    cout<<"queue is empty"<<endl;
    else
    {
       int x = arr[0];
       for(int i=1;i<top;i++)
       {
        arr[i-1] = arr[i];
       }
       top--;
       cout<<x;
    }
   }
};
int main()
{
    Queue q(3);
    q.push(3);
    q.push(2);
    q.push(1);
    q.push(0);
    q.pop();
    q.push(0);
    return 0;
}
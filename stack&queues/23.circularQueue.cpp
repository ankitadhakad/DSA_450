#include<iostream>
using namespace std;
struct Queue
{
    int *arr;
    int front,cap,size;
    Queue(int c)
    {
        arr = new int[c];
        cap = c;
        front = 0;
        size = 0;
    }
    int getFront()
    {
        if(size == 0)
        return -1;
        return front;
    }
    int getRear()
    {
        if(size == 0)
        return -1;
        return (front+size-1)%cap;
    }

    void push(int x)
    {
        if(size == cap)
        return;
        int rear = getRear();
        rear = (rear+1)%cap;
        arr[rear] = x;
        size++;
    }
    int pop()
    {
        if(size == 0)
        return -1;
        front = (front+1)%cap;
        size--;
    }
}
int main()
{

    return 0;
}
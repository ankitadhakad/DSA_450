#include<iostream>
#include <deque>
using namespace std;
class StackDq
{
    private:
    deque<int>dq;
    public:
    void push(int x);
    int pop();
};
void StackDq :: push(int x)
{
    dq.push_front(x);
}
int StackDq :: pop()
{
    int x = dq.front();
    dq.pop_back();
    return x;
}
int main()
{
    return 0;
}
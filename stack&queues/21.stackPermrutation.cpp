#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
// You are given two arrays A and B of unique elements of size N. 
// Check if array B is a stack permutation of the array A or not.
// Stack permutation means that array B can be created from array A using a stack 
// and stack operations.
// Example 1:
// Input:
// N = 3
// A = {1,2,3}
// B = {2,1,3}
// Output:
// 1
// Explanation:
// 1. push 1 from A to stack
// 2. push 2 from A to stack
// 3. pop 2 from stack to B
// 4. pop 1 from stack to B
// 5. push 3 from A to stack
// 6. pop 3 from stack to B

//approach 1 using 2 queues

int isStackPermutationI(int N,vector<int> &A,vector<int> &B){
        //creating two queues to store the input and output stack permutations.
        queue<int> ip,op;
        
        //pushing the elements of input and output stack permutations into the queues.
        for(int i=0;i<N;i++){
            ip.push(A[i]);
            op.push(B[i]);
        }
        
        //creating a stack to simulate the stack operations.
        stack<int> st;
        
        //iterating until the input queue is empty.
        while(ip.size()){
            //storing the front element of the input queue in a temporary variable.
            int tmp=ip.front();
            ip.pop();
            
            //checking if the temporary variable is equal to the front element of the output queue.
            if(tmp==op.front()){
                //if they are equal, then popping the front element from the output queue.
                op.pop();
                
                //iterating until the stack is empty.
                while(st.size()){
                    //checking if the top element of the stack is equal to the front element of the output queue.
                    if(st.top()==op.front()){
                        //if they are equal, then popping the top element from the stack and popping the front element from the output queue.
                        st.pop();
                        op.pop();
                    }
                    //if they are not equal, then breaking out of the loop.
                    else break;
                }
            }
            //if the temporary variable is not equal to the front element of the output queue, then pushing the temporary variable into the stack.
            else st.push(tmp);
        }
        
        //returning whether both the input queue and the stack are empty, indicating that all the stack permutations are possible.
        return (ip.empty() && st.empty());
    }


    //approach 2 wihtout extra space

     int isStackPermutationII(int N,vector<int> &A,vector<int> &B)
    {
        int i = 0;
        int j = 0;
        stack<int>s;
        while(i<N)
        {
            s.push(A[i]);
            while(!s.empty() && B[j] == s.top() && j<N)
            {
                s.pop();
                j++;
            }
            i++;
        }
        return s.empty();
    }
int main()
{
    vector<int>A = {1,2,3};
    vector<int>B = {2,1,3};
    cout<<isStackPermutationI(3,A,B)<<endl;
    cout<<isStackPermutationII(3,A,B)<<endl;
    return 0;
}
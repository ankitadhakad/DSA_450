#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{

public:

vector<int>factorial(int n)
{
    vector<int>res;
    res.push_back(1);
    for(int i=2;i<=n;i++)
    {
        int carry = 0;
        for(int j=0;j<res.size();j++)
        {
            int val = res[j]*i+carry;
            res[j] = val%10;
            carry = val/10;
        }
        while(carry != 0)
        {
            res.push_back(carry%10);
            carry=carry/10;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
};

int main()
{
    int n = 0;
    cout<<"Enter number"<<endl;
    cin>>n;
    Solution s;
    vector<int>fact = s.factorial(n);
    for(int i=0;i<fact.size();i++)
    {
         cout<<fact[i]<<" ";
    }
    return 0;
}
 #include <bits/stdc++.h>
 using namespace std;

 
 int romanToDecimal(string &str) 
    {
        // code here
        int n = str.length();
        
       map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L']=50;
    mp['C']=100;
    mp['D']=500;
    mp['M']=1000;
      int ans = mp[str[n-1]];
      for(int i=n-1;i>=0;i--)
      {
          if(mp[str[i-1]] < mp[str[i]])
          ans-=mp[str[i-1]];
          else ans+=mp[str[i-1]];
      }
      return ans;
    }
    int main()
    {
        string str = "VII";
        cout<<romanToDecimal(str);
        return 0;
    }
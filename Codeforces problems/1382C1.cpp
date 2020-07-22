/*
Problem Make a binary string s equal to another binary string t by choosing a prefix from s , Invert the elements in that prefix and reverse that prefix.
Meaning of Prefix-You have to starting choosing elements from oth index.[You can't Choose any random subset in between the array]
Time Complexity-O(n^2)
Approach-To Make string s such that when we apply the operation mentioned in problem to the whole array we must get string t.
        -Previous Point means that before doing the operation the "ith" bit in string t and (n-i-1)th bit in string s should be opposite.
        - Continued Ahead in  Code
*/

#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    if(s==t){cout<<0<<endl;continue;}
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
      if(t[i]==s[n-1-i])   
      {
        if(s[0]!=s[n-i-1])  //Before the prefix is inverted and reversed, s[0] should be opposite of what we need in place of s[n-i-1], Because after inverse and reverse s[0] will come at place of s[n-1-i]
        {
         if(s[0]=='1')s[0]='0';
         else s[0]='1';
         ans.pb(0);
        }
        for(int j=0;j<=(n-i-1);j++)      //Inverting the prefix 1->0 and 0->1
        {
          if(s[j]=='1')s[j]='0';
          else s[j]='1';
        }
       reverse(s.begin(),s.begin()+n-i);     //Reversing the prefix.
       ans.pb(n-i-1);  
      }
    }
    ans.pb(n-1);       //To Make string s such that when we apply the operation mentioned in problem to the whole array we must get string t,So we made the string required to be able to be made same as string t after the application is done(invert then reverse).
    cout<<ans.size()<<" ";
    for(auto x:ans)cout<<x+1<<" ";
    cout<<endl;
  }
}

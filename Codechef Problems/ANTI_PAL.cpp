#include<bits/stdc++.h>
using namespace std;
#define pb push_back


signed main()
{
  int t;
  cin>>t;

  while(t--)
  {
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n%2!=0){cout<<"NO"<<endl;continue;}
    int half=n/2;
    map<char,int>hash;
    for(int i=0;i<n;i++)hash[s[i]]++;
    vector<char>ans;
    int sum=0;
    char left;
    int howmuch=0;

    for(auto x: hash)
    {
      int check=sum+x.second;
      if(check<=half)
      {
        sum+=x.second;
        for(int i=0;i<x.second;i++)ans.pb(x.first);
        if(sum==half)sum=0;
      }
      else
      {
        left=x.first;
        int minus=check-half;
        howmuch=minus;
        int till=x.second-minus;
        for(int i=0;i<till;i++)ans.pb(x.first);
        sum=0;
      }
    }

    for(int i=0;i<howmuch;i++)ans.pb(left);
    
    //Checking if its anti-palindrome or not 
    int ok=1;
    for(int i=0,j=n-1;i<j;i++,j--)
    {
      if(ans[i]==ans[j]){ok=0;break;}
    }

    if(ok==0){cout<<"NO"<<endl;continue;}

    cout<<"YES"<<endl;
    for(auto x: ans)cout<<x;
    cout<<endl;
  }

}
/*1.Never overkill a problem.
    2.think of test cases to clarify the approach/doubts.
    3.Don't give up!
    4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
    5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
*/ 

// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
#else 
#define freopen 
#endif
 
#define pb push_back
#define pf push_front
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define float double
signed main()
{
  freopen
  ios
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    string s;
    cin>>s;

    for(int i=0;i<n;i++)
    {
      if(s[i]=='(')s[i]='1';
      else s[i]='0';
    }
    int nxt[n+2]={0};
    for(int i=0;i<n;i++)nxt[i]=-1;
    
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
      if(st.size()==0 && s[i]=='0')st.push(i);
      else if(s[i]=='0' && st.size()>0)
      {
        nxt[i]=st.top();
        st.pop();
        st.push(i);
      }
    }
    int pos=n;
    int ans=0;

    for(int i=0;i<n;)
    {
      if(i==n-1){pos=i; break;}
      if(s[i]==s[i+1]){ans++;i+=2;}
      else if(s[i]=='1' && s[i+1]=='0'){ans++;i+=2;}
      else if(s[i]=='0' && s[i+1]=='1')
      {
         if(nxt[i]!=-1)
         {
           i=nxt[i]+1;
           ans++;
         }
         else {pos=i;break;}
      }

    }

    cout<<ans<<" "<<n-pos<<endl;
  }
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
  5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
  6.Check datatype of variables, sometimes wrong datatype lead to WA.
*/ 
    
    

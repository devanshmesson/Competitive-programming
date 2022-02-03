// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#else 
#define freopen 
#endif

#define pb push_back
#define pf push_front
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define float double

int divisorsum(int n)
{
  int ans=0;
  for(int i=1;i*i<=n;i++)
  {
    if(n%i==0)
    {   
        if(i==(n/i))ans+=i;
        else ans+=i+(n/i);
    }
  }
  return ans;
}
signed main()
{
  freopen
  ios
  int t;
  cin>>t;
  while(t--)
  {
    int x,a,b;
    cin>>x>>a>>b;
    if(divisorsum(b)==a && a==x){cout<<b<<endl; continue;}
    if(x%a!=0){ cout<<-1<<endl; continue;}
    int gcdd=x/a;
    int temp_n=gcdd*b;
    int limit=1e9;
    if(temp_n>limit){ cout<<-1<<endl; continue;}
    if(divisorsum(temp_n)==x){cout<<temp_n<<endl; continue;}
    cout<<-1<<endl;
  }
}
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 

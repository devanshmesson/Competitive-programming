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
    int a[n+1];
    a[1]=1;
    a[2]=2;
    int hash[100001]={0};
    hash[1]=1;
    hash[2]=1;
    for(int i=3;i<=n;i++)
    {
      vector<int>k;
      int sum=0;
      for(int j=i-1;j>=1;j--)
      {
        sum+=a[j];
        k.pb(sum);
      }
      int ad=3,flag=0;
      while(1)
      {
        flag=0;
        for(int v=0;v<k.size();v++)
        {
          int y=k[v]+ad;
          if(y%(v+2)==0){flag=1;break;}
        }
        if(flag==0)
        {
          a[i]=ad;
          hash[ad]=1;
          break;
        }
        hash[ad]++;
        ad++;
        if(hash[ad]>=1)while(hash[ad]>=1)ad++;
      } 
    } 
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
 }
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
*/ 

#include <bits/stdc++.h>
#define int long long int
const int mod=1000000007;
using namespace std;
inline int multiply(int a,int b) {return (int)((long long) a* b % mod);}
int power(int x,unsigned int y)
{
	int res=1;
    x=x%mod;
	while(y>0)
	{
		if(y&1)res=(res*x)%mod;
		y=y>>1;
		x=(x*x)%mod;
	}
	return res;
}


main()
{
   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   int x,n;
   cin>>x>>n;
   vector<int> p;
   for(int i=2;i*i<=x;i++)
   {
       if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
   }
   if(x>1)p.push_back(x);
   int ans=1;
   int s=p.size();
   for(int i=0;i<s;i++)
   {
       int cnt=0;
      int y=p[i];int k=n;
      while(k/y)
      {
          cnt+=k/y;
          cnt=cnt%(mod-1);
          if(p[i]>1e18/y)break;
          y=y*p[i];
      }
      ans=multiply(ans,power(p[i],cnt));
   }
   cout<<ans<<endl;
}

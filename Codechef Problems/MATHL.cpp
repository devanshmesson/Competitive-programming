//Biteration C problem
#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  long long int fac[1000005],ans[1000005];
   long long int mod=1000000007;
    fac[0]=1;ans[0]=1;
        for(int i=1;i<1000003;i++)
        {
            fac[i]=(fac[i-1]*i)%mod;
 		    ans[i]=(ans[i-1]*fac[i])%mod;
	    }
	int t;
 	cin>>t;
 	while(t--)
 	{
 		int n;
 		cin>>n;
 		cout<<ans[n]<<'\n';
 	}
 	return 0;
 }

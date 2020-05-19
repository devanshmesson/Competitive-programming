#include<bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int

int32_t main()
{
	io
	int n,ans=0;
	cin>>n;
	for(int i=5;i<=n;i*=5)
	{
		if(n/i>0)ans+=n/i;
		else break;
	}
	cout<<ans<<endl;
}        


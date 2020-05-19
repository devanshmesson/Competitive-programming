#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
int32_t main()
{
	io
	//freopen
	int n;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++)cin>>a[i];
    int ans=0;
	for(int i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
		{
			ans+=a[i]-a[i+1];
			a[i+1]=a[i];
		}
	}
	cout<<ans<<endl;
}                                               

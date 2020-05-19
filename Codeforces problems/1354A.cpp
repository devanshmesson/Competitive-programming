#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
int32_t main()
{
	freopen
	io
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(b>=a){cout<<b<<endl;continue;}
		if((c-d)<=0){cout<<-1<<endl;continue;}
		int up=a-b;
		int div=c-d;

		int ans=1;
		ans=(up/div)+(up%div!=0);
		cout<<(ans*c)+b<<endl;

    }
}

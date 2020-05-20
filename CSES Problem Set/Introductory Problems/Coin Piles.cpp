#include<bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int

int32_t main()
{
	io
	int  t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		if((2*a-b>=0) && (2*b-a>=0) && ((2*a-b)%3==0) && ((2*b-a)%3==0))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;

	}
}      


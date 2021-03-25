#include<bits/stdc++.h>
using namespace std;
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define int long long int
main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,x;
		cin>>n>>m>>x;
		int col=(x/n) + (x%n!=0);
		int row=x%n;
		if(row==0)row=n;
		int ans = m*(row-1)+1+col-1;
		cout<<ans<<endl;
	}
}

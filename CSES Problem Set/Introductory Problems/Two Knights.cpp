#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
int32_t main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int ans=(i*i)*((i*i)-1)-(4*2)-24-((i-4)*4*4)-16-(24*(i-4))-(8*(i-4)*(i-4));
		cout<<ans/2<<endl;
	}

}        


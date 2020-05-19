#include<bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int

int32_t main()
{
	io
	int n;
	cin>>n;
	int odd=ceil((float)n/(float)2);
	int even=n/2;
	if(abs((odd*odd)-((even*even)+even))%2==0)
	{
		int sw=abs((odd*odd)-((even*even)+even));
		sw/=2;
		int diff=odd-sw;
		cout<<"YES"<<endl;
		int start;
		if(n%2==0)start=n;
		else start=n-1;
		unordered_map<int,int>mp;
		cout<<odd<<endl;
		while(sw>0)
		{
			cout<<start<<" ";
			mp[start]++;
			start-=2;
			sw--;
		}
		start=1;
		while(diff>0)
		{
			cout<<start<<" ";
			mp[start]++;
			start+=2;
			diff--;
		}

		cout<<endl;
    cout<<even<<endl;

		for(int i=1;i<=n;i++)
		{
			if(!mp[i])cout<<i<<" ";
    }

	}
	else cout<<"NO"<<endl;


}        


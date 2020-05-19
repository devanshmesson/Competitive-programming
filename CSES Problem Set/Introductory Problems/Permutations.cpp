#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<map>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define freopen //comment
#endif
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int

int32_t main()
{
	io
	//freopen
	int n;
	cin>>n;
	if(n==1)cout<<1<<endl;
	else if(n<=3)cout<<"NO SOLUTION"<<endl;
	else if(n==4)
	{
		cout<<2<<" "<<4<<" "<<1<<" "<<3<<endl;
	}
	else
	{
		int in;
		for(int i=1;i<=n;i+=2)
		{
			cout<<i<<" ";
			in=i;
		}
		cout<<in-3<<" ";

		for(int i=2;i<=n;i+=2)
		{
			if(i!=(in-3))cout<<i<<" ";
		}
	}
}                                               

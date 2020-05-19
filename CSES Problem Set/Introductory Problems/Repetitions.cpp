#include<bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int

int32_t main()
{
	io
	//freopen
	string s;
	cin>>s;
	int m=INT_MIN,ans=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==s[i+1])ans++;
		else 
		{
			m=max(m,ans);ans=1;
		}	
	}
	cout<<m<<endl;
}                                               

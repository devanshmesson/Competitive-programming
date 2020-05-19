#include<bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int32_t main()
{
	freopen
	io
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int sz=s.size();
		
		int a=0,b=0,c=0,ans=0,flag=1;
		int d[5]={0};
		int left=0;int min=INT_MAX;
		
		for(int i=0;i<sz;i++)
		{
			if(s[i]=='1')a=1;
		    if(s[i]=='2')b=1;
		    if(s[i]=='3')c=1;
		    d[s[i]-'0']++;
		    if(a==1 && b==1 && c==1)
		    {
		    	flag=0;
		    	while(d[s[left]-'0']>1)
			    {
				if(d[s[left]-'0']>1)d[s[left]-'0']--;
				left++;
			    }
			int l=i-left+1;
			if(min>l)min=l;

		    }


		}
		if(flag==1){cout<<0<<endl;continue;}
		if(flag==0)cout<<min<<endl;

    }
}

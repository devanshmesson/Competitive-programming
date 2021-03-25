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
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
        
    int fi=-1;
		for(int i=0;i<n;i++)if(s[i]=='*'){fi=i;break;}
		int si=-1;
		for(int i=n-1;i>=0;i--)if(s[i]=='*'){si=i;break;}
		if(fi==si){cout<<1<<endl;continue;}
	    if(abs(fi-si)<=k){cout<<2<<endl;continue;}
        int ans=2;        
        int upd=fi;
        while(abs(upd-si)>k)
        {
          int st=upd+k;
          if(st > si)st=si;
	     for(int i=st;i>=upd;i--)
	     {
	     	if(s[i]=='*')
	    	{
	    	  upd=i;
	    	  ans++;
          break;
	    	}
	     }
	   }
    cout<<ans<<endl;
	}
}

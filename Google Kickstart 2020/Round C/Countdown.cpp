#include<bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int32_t main()
{

	int t;
	cin>>t;
	for(int g=1;g<=t;g++)
	{
	    int n,k;
	    cin>>n>>k;
	    int a[n+1];
	    for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int sum=k,ans=0;
        if(k==1)
        {
            for(int i=0;i<n;i++)ans+=(a[i]==1);
            cout<<"Case #"<<g<<":"<<" "<<ans<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
        {
          if(a[i]==sum)
          {
              if(sum==1)
              {
              ans++;
              sum=k;
              continue;
              }
          }
          else if(a[i]!=sum)
          {
             if(a[i]!=k)sum=k;
             else sum=k-1;
             continue;
          }
          sum--;
        }
        cout<<"Case #"<<g<<":"<<" "<<ans<<endl;

    }
}

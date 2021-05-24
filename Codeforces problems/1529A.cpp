#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define freopen freopen("input.txt","r",stdin);freopen("output1.txt","w",stdout);
main()
{
    // freopen
    int t;
    cin>>t;
    while(t--)
    {
      int n;
      cin>>n;
      int a[n+1];
      int mini=INT_MAX;
      for(int i=0;i<n;i++)
      	{
      		cin>>a[i];
      		mini=min(mini,a[i]);
      	}
         
         int cnt=0;
      	for(int i=0;i<n;i++)
      	{
      		if(a[i]==mini)
      		{
            cnt++;
      		}
      	}

      	cout<<n-cnt<<endl;

    }
}

    

#include<bits/stdc++.h>
using namespace std;
#define int long long int
// #define freopen freopen("input.txt","r",stdin);freopen("output1.txt","w",stdout);
int a[100005];
main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n,k,ans=0;
    	cin>>n>>k;
    	vector<int>pos[k+1];
    	for(int i=0;i<n;i++)
    	{
    	  cin>>a[i];
    	  pos[i%k].push_back(a[i]);
    	}
        
        unordered_map<int,int>mp;
    	for(int i=0;i<k;i++)
    	{
    	  mp.clear();
          for(auto x:pos[i])
          {
          	mp[x]++;
          }
          int maxi=INT_MIN;
          for(auto x:mp)
          {
            maxi=max(maxi,x.second);
          }
          
          ans+=pos[i].size()-maxi;
    	}

    	cout<<ans<<endl;

    }
}

    

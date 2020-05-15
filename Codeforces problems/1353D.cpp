#include<iostream>
#include<queue>
#include<set>
using namespace std;

#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define int long long int
#define mk make_pair

int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		    int n;
		    cin>>n;
		    int ans[n+1];
        priority_queue<pair<int,pair<int,int> > >pq;
        int left=1,rit=n,mid,len;
        pq.push({n,{1,n}});

        for(int i=1;i<=n;i++)
        {
            left=-(pq.top().second.first);
        	  rit=(pq.top().second.second);
        	  len=rit-abs(left)+1;
            mid=(abs(left)+rit)/2;
            ans[mid]=i;
            pq.pop();
            if(abs(left)==rit)continue;
            len=mid-abs(left);  
            if(left>0)left=0-left;
            if(len>0)pq.push({len,{left,(mid-1)}});
            len=rit-mid;
            if(len>0)pq.push({len,{-(mid+1),rit}});

        }
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;

	}
}

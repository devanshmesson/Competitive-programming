#include<bits/stdc++.h>
using namespace std;
#define int long long int
main()
{
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    int n,m,k;
    cin>>n>>m>>k;
    //Use difference array to calculate frequencey of a number
    //in the matrix.As the numbers are in particular range, we can take 
    //advantage of difference arrays.
    int diff[n+m+1]={0};
    for(int i=1;i<=n;i++)
    {
      int l=i+1;
      int r=i+m;
      diff[l]+=1;
      diff[r+1]-=1;
    }
    int ans=0;
    for(int i=2;i<=n+m;i++)
    {
      if(i>2)diff[i]+=diff[i-1];

      if(diff[i]%2==1)
      {
        ans^=i+k;
      }
    }
    cout<<ans<<endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
#define int long long int
int power(int a,int b)
{
    int mod=1000000007;
	if(b==0)
	return 1;

	if(b==1)
	return a;

	int temp = power(a,b/2);
	if(b%2)
	{
		return (temp*((temp*a)%mod))%mod;
	}

	return (temp*temp)%mod;
}
main()
{
    #define int long long int
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int h,w,t,high,low,cnt=0,mod=1000000007;
    cin>>h>>w;
    int a[h][w];
    memset(a,-1,sizeof(a));
    for(int i=0;i<h;i++)
    {
          cin>>t;
          for(int j=0;j<t;j++)
          {
             if(a[i][j]==0){cout<<0; return 0;}
             a[i][j]=1;
          }
        if(t<w)
        {
            if(a[i][t]==1){cout<<0; return 0;}
            a[i][t]=0;
        }
    }

    for(int i=0;i<w;i++)
    {
        cin>>t;
        //if(a[t][i]==0)return 0;
        for(int j=0;j<t;j++)
        {
             if(a[j][i]==0){cout<<0; return 0;}
             a[j][i]=1;
        }
        if(t<h)
        {
            if(a[t][i]==1){cout<<0; return 0;}
            a[t][i]=0;
        }
    }
    for(int k=0;k<h;k++)
      {
          for(int m=0;m<w;m++) if(a[k][m]==-1)cnt=(cnt+1)%mod;
      }

      cout<<power(2,cnt);

    return 0;
}

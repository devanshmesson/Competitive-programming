#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
    int n,l,r;
    cin>>n>>l>>r;
    int minsum=0,j=1,in,flag=1;
    for(int i=1;i<=n;i++)
    {
        if(l==0){flag=0;in=i;break;}
        minsum+=j;
        j*=2;
        l--;
    }
    if(flag==0)for(int i=in;i<=n;i++)minsum+=1;
    j=1;
    int maxsum=1,in1;
    r--;
    flag=1;
    for(int i=2;i<=n;i++)
    {
     if(r==0){flag=0;in=i;in1=j;break;}
     j*=2;
     maxsum+=j;
     r--;
    }
    //cout<<maxsum<<" "<<in<<" "<<in1<<endl;
    if(flag==0)for(int i=in;i<=n;i++)maxsum+=in1;

    cout<<minsum<<" "<<maxsum<<endl;
}

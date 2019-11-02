#include <bits/stdc++.h>
using namespace std;
long long int fac(int b,int a)
  {
    if(a>b-a)a=b-a;
    long long ans=1;
    for(int i=1;i<=a;i++)
    {
        ans*=b-a+i;
        ans/=i;
    }
   return ans;
}

int main()
{
   long long int t;
   cin>>t;
   while(t--)
   {
    long long int n,k,a,cnt=0,r,f,m,maxm=0,mode=1,c=0,c1=0,flag=0;
    cin>>n>>k;
    long long int v[n];
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v,v+n);
    int last=v[1];

    for(int i=0;i<=k-1;i++)
    {
        if(v[i]==v[i+1]){cnt++;flag=1;}
        else cnt=0;
        if(cnt>=maxm) {maxm=cnt; mode=v[i]; c1=cnt;}
        if(v[i]!=v[i+1]){mode=v[k-1];}
    }
    if(c1==0)mode=v[k-1];
    for(int i=k;i<n;i++)
    {
        if(v[i]==mode)c++;
    }
     if(n==k)
     {
         cout<<"1"<<endl;
     }
     else
     {
          m=c+cnt;
          r=cnt;

          f=fac(m,r);
       cout<<f<<endl;
     }
    }
}



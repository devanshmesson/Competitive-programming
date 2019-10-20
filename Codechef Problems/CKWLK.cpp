#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y)
{
    long long int ans =1;
    while(y>0)
    {
        if(y&1) ans=ans*x;
        y=y>>1;
        x=x*x;
    }
    return ans;
}

int main()
{
    #define int long long int
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,t1,k=0,cnt=1,flag=1,f=1;
        cin>>n;
        t1=n;

        if(n/10==0 && n!=1){cout<<"No"<<endl; continue;}
        if(n==1){cout<<"Yes"<<endl; continue;}
        if(n==10 || n==20){cout<<"Yes"<<endl; continue;}
        while(k==0 && t1!=0)
        {
            t1=t1/10;
            k=t1%10;
            if(k==0){f=0;cnt++;}
        }
        //cout<<"---->"<<cnt<<endl;
        if(f!=0)cnt=0;
        if(cnt==0)t1=n;

       for(int i=0;i<=cnt;i++)
       {
           if(power(2,i)==t1){flag=0;cout<<"Yes"<<endl;break;}
       }
       if(flag==1)cout<<"No"<<endl;

    }
    return 0;
}

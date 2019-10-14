#include <bits/stdc++.h>
using namespace std;
int main()
{
    #define int long long int
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,k,cnt=1,cnt1=1;
        cin>>a>>b>>c>>d>>k;
        for(int i=c;i<a;i=i+c)
        {
            cnt++;
        }
        for(int i=d;i<b;i=i+d)
        {
            cnt1++;
        }
 
       /*if(cnt<k)cnt=k-cnt;
       if(cnt1<k)cnt1=k-cnt;*/
       if(cnt+cnt1>k){cout<<"-1"<<endl;continue;}
       cout<<cnt<<" "<<cnt1<<endl;
    }
 
 
 
 
    return 0;
}

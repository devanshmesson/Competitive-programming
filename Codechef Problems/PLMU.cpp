#include <bits/stdc++.h>
using namespace std;
int ncr(int n1, int r1)
{
long long p = 1, k = 1;

     if(n1>=r1)
     {
      r1=n1-r1;

    if (r1 != 0)
        {
        while (r1)
        {
            p *= n1;
            k *= r1;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n1--;
            r1--;
        }
    }

    else
        p = 1;
     }
     else p=0;


    return p;
}
int main()
{
    ios::sync_with_stdio();cin.tie();cout.tie();
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
        int n,cnt=0,cnt1=0,temp=0,temp1,a,ans=0;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++) { cin>>a; v.push_back(a);}
        for(int i=0;i<n;i++) if(v[i]==0)cnt++;
        for(int i=0;i<n;i++) if(v[i]==2)cnt1++;
        int y=2;

       ans=ncr(cnt,2)+ncr(cnt1,2);
       cout<<ans<<endl;
    }

}

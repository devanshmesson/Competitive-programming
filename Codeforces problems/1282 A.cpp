#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    #define int long long int
    ios::sync_with_stdio(0);cin.tie();cout.tie();
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,r,l,mi,ma,ans=0,temp,bi;
        cin>>a>>b>>c>>r;
        l=(c-r);
        bi=(c+r);
        mi=min(a,b);
        ma=max(a,b);
 
        if(c>=min(a,b) && c<=max(a,b))
        {
            if(l<=mi)l=mi;
            if(bi>=ma)bi=ma;
            ans=(ma-mi)-(fabs(bi-l));
 
        }
        else
        {
            if(l>=min(a,b) && l<=max(a,b))
            {
                temp=fabs(c-mi);
                if(temp>=fabs(c-ma))
                {
                    ans=ma-mi-(fabs(ma-l));
                }
 
            }
            else if(bi>=min(a,b) && bi<=max(a,b))
            {
                 temp=fabs(c-ma);
                if(temp>=fabs(c-mi))
                {
                    ans=ma-mi-(fabs(mi-bi));
                }
 
            }
            else if(l<min(a,b) && l<max(a,b) && bi<min(a,b) && bi<max(a,b))
            {
                ans=ma-mi;
            }
            else if(l>min(a,b) && l>max(a,b) && bi>min(a,b) && bi>max(a,b))
            {
                ans=ma-mi;
            }
           else
            ans=0;
        }
        cout<<ans<<endl;
 
    }
    return 0;
}

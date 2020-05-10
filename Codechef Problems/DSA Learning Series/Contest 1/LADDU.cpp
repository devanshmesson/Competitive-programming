#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n,c;
       cin>>n;
       string s,t;
       cin>>s;
       int sum=0;

        for(int i=0;i<n;i++)
        {
            cin>>t;
            if(t=="CONTEST_WON")
            {
                cin>>c;
                sum+=300;
                if(c<=20)sum+=(20-c);
            }
            else if(t=="TOP_CONTRIBUTOR")sum+=300;
            else if(t=="BUG_FOUND")
            {
                cin>>c;
                sum+=c;
            }
            else if(t=="CONTEST_HOSTED")sum+=50;
        }
        if(s=="INDIAN")cout<<sum/200<<endl;
        else cout<<sum/400<<endl;



    }
}

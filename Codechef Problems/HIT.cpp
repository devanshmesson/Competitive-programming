//Can Anybody tell me why i got WA in this Problem.Following is the code:

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,cnt=0,flag=1,x=60,y=75,z=90;
        cin>>n;
        vector<int>h;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            h.push_back(a);
        }
        sort(h.begin(),h.end());
        if (h[n/4]==h[n/4-1] || h[n/4+n/4]==h[n/4+n/4-1] || h[n/4+n/4+n/4]==h[n/4+n/4+n/4-1])flag=0;
        if(flag==0)cout<<"-1"<<endl;
        else
        {
           x=h[n/4];
           y=h[n/4+n/4];
           z=h[n/4+n/4+n/4];
           cout<<x<<" "<<y<<" "<<z<<endl;
        }



    }
    return 0;
}

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
        int n,a,b,c,te,itr,ans=1,an=100000000009,ind,ann=10000000009,indi;
        cin>>n>>a>>b>>c;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            cin>>te;v.push_back(te);
        }
        //if(n==1){cout<<abs(b-v[0])+c+abs(v[0]-a)<<endl;continue;}

        //sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            if(an>=abs(b-v[i])+c+abs(v[i]-a))
            {
                an=abs(b-v[i])+c+abs(v[i]-a);
            }
        }
        /*for(int i=0;i<n;i++)
        {
            if(ann>=abs(a-v[i]))
            {
                ann=abs(a-v[i]);
                indi=v[i];
            }
        }*/



        cout<<an<<endl;
    }
    return 0;
}

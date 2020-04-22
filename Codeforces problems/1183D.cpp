#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    #define pb push_back
    int t;
    cin>>t;
    while(t--)
    {
       int n,a,sum=0,sz=0;
       cin>>n;
       vector<int>v(n+1);
       for(int i=0;i<n;i++)
       {
           cin>>a;
           v[a]++;
           sz++;
       }
       sort(v.begin(),v.end(),greater<int>());
       vector<int>visit(n+1);
       visit[v[0]]=1;
       for(int i=1;i<sz;i++)
       {
        if(visit[v[i]]==1)
        {
            if(v[i-1]>0 && (v[i-1]-1)>0){v[i]=v[i-1]-1;}
            else v[i]=0;
            visit[v[i]]=1;
        }
        else visit[v[i]]=1;
       }
       for(int i=0;i<sz;i++)
       {
         sum+=v[i];
       }
       cout<<sum<<endl;


    }







    return 0;
}

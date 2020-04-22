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
       int n,a,sz=0,sum=0;
       cin>>n;
       vector<int>v(n+1000);
       vector<int>k;
       set<int>w;
       for(int i=0;i<n;i++)
       {
           cin>>a;
           v[a]++;
           w.insert(a);

       }
int h,r;
       for(auto j=w.begin();j!=w.end();j++)
       {
           h=*j;
           r=v[h];
           k.pb(r);
           sz++;
       }
       sort(k.begin(),k.end(),greater<int>());
       vector<int>visit(n+1000);
       visit[k[0]]=1;
       for(int i=1;i<k.size();i++)
       {
        if(visit[k[i]]==1)
        {
            if(k[i-1]>0 && (k[i-1]-1)>0){k[i]=k[i-1]-1;}
            else k[i]=0;
            visit[k[i]]=1;
        }
        else visit[k[i]]=1;
       }

       for(int i=0;i<k.size();i++)
       {
         sum+=k[i];
       }
       cout<<sum<<endl;


    }
    return 0;
}

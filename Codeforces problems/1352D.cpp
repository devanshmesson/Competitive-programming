#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n,l=0,r,ansl=0,ansr=0,lastl=0,lastr=0,presl=0,presr=0,cnt=0,sumr=0,suml=0;
       map<int,int>visit;
       cin>>n;
       int a[n+1];
       for(int i=0;i<n;i++)cin>>a[i];
       r=n-1;
       while(l<=r)
       {
           if(cnt%2==0)
           {

           while(l<=r && presl<=sumr)
           {
               if(visit[l]==0)
               {
               visit[l]++;
               presl+=a[l];
               l++;
               }
           }
           ansl+=presl;
           suml=presl;
           presl=0;
           }
           else if(cnt%2!=0)
           {

           while(l<=r && presr<=suml)
           {
               if(visit[r]==0)
               {
               visit[r]++;
               presr+=a[r];
               r--;
               }
           }
           ansr+=presr;
           sumr=presr;
           presr=0;
           }
           cnt++;
       }
       cout<<cnt<<" "<<ansl<<" "<<ansr<<endl;

    }
}

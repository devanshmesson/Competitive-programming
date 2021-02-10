#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int
#define endl "\n"

main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n,m;
      cin>>n>>m;
      int a[n+1],b[n+1],c[m+1];
      for(int i=1;i<=n;i++)cin>>a[i];
      for(int i=1;i<=n;i++)cin>>b[i];
      for(int i=1;i<=m;i++)cin>>c[i];

      vector<int>unequal[n+1],equal[n+1];
      int achieve=0;

      for(int i=1;i<=n;i++)
      {
        if(a[i]!=b[i])
        {
          unequal[b[i]].pb(i);
          achieve++;
        }
        else equal[b[i]].pb(i);
      }

      if(unequal[c[m]].size()==0 && equal[c[m]].size()==0){cout<<"NO"<<endl;continue;}

      int visit[n+1]={0},index[n+1]={0},ans[m+1],upd=-1;
      int ok=1;

      for(int i=m;i>=1;i--)
      {
         int cc=c[i];
         if(achieve==0 && upd!=-1)
         {
           ans[i]=upd;
         }
         else if(index[cc]<unequal[cc].size())
         {
           int ind=index[cc];
           index[cc]++;
           ans[i]=unequal[cc][ind];
           upd=ans[i]; //painted plank index
           achieve--;
         }
         else if(equal[cc].size()>0)
         {
           ans[i]=equal[cc][0];
           upd=ans[i];

           //case:1 colour is include in the equal array.
              // paint same coloured plank
         }
         else if(upd!=-1)
         {
           ans[i]=upd;
         }
         else {ok=0;break;}

      }

      if(ok==0 || achieve>0){cout<<"NO"<<endl;continue;}

      cout<<"YES"<<endl;
      for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
      cout<<endl;
    }
}

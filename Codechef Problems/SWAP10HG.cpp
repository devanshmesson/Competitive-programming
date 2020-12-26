#include <bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
vector<int>path;
#define endl "\n"
vector<vector<int>>visit;
int okay,previous,mark;
//#define endl 
void dfs(int n,vector<int>bipartite[],vector<vector<int>>mp)
{ 
  // cout<<n<<" "<<endl;
  for(int i=0;i<bipartite[n].size();i++)
  {
    int f,s;
    if(bipartite[n][i]>n)
    {
      f=n;
      s=bipartite[n][i];
    }
    else
    {
      s=n;
      f=bipartite[n][i];
    }

    if(visit[f][s]==0 && visit[s][f]==0) 
    {
      visit[f][s]=1;
      visit[s][f]=1;
      path.pb(mp[f][s]);
      dfs(bipartite[n][i],bipartite,mp);
    }
  }
}

int main()
{
  freopen
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    string s,p;
    cin>>s>>p;
    if(s[0]==0 && p[0]==1){cout<<"No"<<endl;continue;}

    for(int i=0;i<n;i++)
    {
      if(s[i]!=p[i] && s[i]=='1')
      {
        char q;
        if(s[i]=='1')q='0';
        else q='1';

        for(int j=i+1;j<n;j++)
        {
           if(s[j]==q && s[j]!=p[j])
           {
             char temp=s[i];
             s[i]=s[j];
             s[j]=temp;
             break;
           }
        }
      }
    }

    if(s!=p)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
  }
}

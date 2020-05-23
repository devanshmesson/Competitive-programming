#include<bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define endl "\n"
 
main() 
{ 
  io
  int n,m,k,a;
  cin>>n>>m>>k;
  vector<int>apart,apli;
  unordered_map<int,int>mp;

  int ans=0,i=0,j=0;
  for(int i=0;i<n;i++){cin>>a;apli.push_back(a);}
  for(int i=0;i<m;i++){cin>>a;apart.push_back(a);}
  
  sort(apart.begin(),apart.end());
  sort(apli.begin(),apli.end());

    while(i<n && j<m)
    {
      if(apart[j]>=(apli[i]-k) && apart[j]<=(apli[i]+k))
       {
        i++;
        j++;
        ans++;
       }
       else if((apli[i]-k)>apart[j])
       {
         j++;
       }
       else if((apli[i]-k)<apart[j])i++;


    }
  
  cout<<ans<<endl;
}


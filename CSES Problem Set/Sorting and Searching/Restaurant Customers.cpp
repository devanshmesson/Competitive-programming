#include<bits/stdc++.h>
using namespace std;

main() 
{ 
 int n,a,b,c=0,mi=INT_MAX,ma=INT_MIN;
 unordered_map<int,int>pl;
 unordered_map<int,int>ml; 
 cin>>n;
 vector<int>r;
 for(int i=0;i<n;i++)
 {
  cin>>a>>b;
  mi=min(mi,a);
  ma=max(ma,b);
  pl[a]=1;
  ml[b]=1;
  r.push_back(a);
  r.push_back(b);
}
sort(r.begin(),r.end());
int ans=INT_MIN,sum=0;

for(int i=0;i<r.size();i++)
{
  if(pl[r[i]])sum++;
  else if(ml[r[i]])sum--;
  ans=max(ans,sum);
}
cout<<ans<<endl;
}

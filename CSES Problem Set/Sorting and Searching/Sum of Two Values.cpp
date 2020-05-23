#include<bits/stdc++.h>
using namespace std;

main() 
{ 
 int n,x,b;
 cin>>n>>x;
 vector<pair<int,int>>a;
 for(int i=0;i<n;i++)
 {
   cin>>b;
   a.push_back({b,i});
 }

 sort(a.begin(),a.end());
int i=0,j=n-1,in1,in2,flag=1;

while(i<j)
{
  if(a[i].first+a[j].first>x)j--;
  else if(a[i].first+a[j].first<x)i++;
  else if(a[i].first+a[j].first==x){flag=0;in1=a[i].second;in2=a[j].second;break;}
}  
if(!flag)cout<<in1+1<<" "<<in2+1<<endl;
else cout<<"IMPOSSIBLE"<<endl;
}

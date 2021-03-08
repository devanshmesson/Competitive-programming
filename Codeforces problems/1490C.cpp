#include<bits/stdc++.h>
using namespace std;

long long int x;

int binarysearch(long long int a,int i)
{
  int l=1,r=10000,cnt=0;
  while(l<=r)
  {
    int mid=(l+r)/2;
    long long ans=mid*1LL*mid*mid;
    long long fin=a+ans;
    if(fin>x){r=mid-1;}
    else if(fin==x){return 1;}
    else if(fin<x){l=mid+1;}
  }
  return 0;
}
main()
{
 ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 int t;
 cin>>t;
 while(t--)
 {
  bool ans=0;
  cin>>x;
  int flag=0;
  if(x==1){cout<<"NO"<<endl;continue;}
  for(int i=1;i<=10000;i++)
  {
    long long int a=i*1LL*i*i;
    ans=binarysearch(a,i);
    if(ans==1)break;
  }

  if(ans==1)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

 }
}

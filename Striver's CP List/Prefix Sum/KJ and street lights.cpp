//Link - https://www.hackerrank.com/contests/ab-yeh-kar-ke-dikhao/challenges/kj-and-street-lights/problem
#include<bits/stdc++.h>
using namespace std;

long long int diff[200002]={0};
void init_diff_array( long long int line[], long long int n)
{
  diff[0]=line[0];
  for(int i=1;i<=n;i++)
  {
    diff[i]=line[i]-line[i-1];
  }
  diff[n]=0;
}
int main()
{
  #define int long long int
  int n,p;
  cin>>n>>p;
  int x[n],r[n];
  int line[p+1]={0};
  init_diff_array(line,p);

  for(int i=0;i<n;i++)
  {
    cin>>x[i]>>r[i];
    int a=x[i]-r[i];
    int b=x[i]+r[i];
    if(a<0)a=0;
    if(b>p)b=p;
    diff[a]+=1;
    diff[b+1]-=1;
  }
  for(int i=1;i<=p;i++)
  {
    diff[i]=diff[i]+diff[i-1];
  }
  for(int i=0;i<=p;i++)
  {
    if(diff[i]>1)diff[i]=0;
  }
  int maxi=INT_MIN,sum=0;
  for(int i=0;i<p;i++)
  {
    if(diff[i]==diff[i+1] && diff[i]==0)sum++;
    else sum=0;
    maxi=max(maxi,sum);
  }
  cout<<maxi+1<<endl;
}

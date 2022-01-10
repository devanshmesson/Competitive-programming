// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;
int d1[1000009]={0},d2[1000009]={0};
int main()
{
  int n;
  cin>>n;
  int q;
  cin>>q;
  while(q--)
  {
    int l,r;
    cin>>l>>r;
    //adding 1-L
    d1[l]+=(1-l);
    d1[r+1]-=(1-l);

    //adding i smartly by marking 1
    d2[l]++;
    d2[r+1]--;
  }
  for(int i=2;i<=n;i++)
    {
      d1[i]+=d1[i-1];
      d2[i]+=d2[i-1];
    }
  for(int i=1;i<=n;i++)
  {
    if(d2[i]>0)d1[i]+=d2[i]*i;
  }
  int m;
  cin>>m;
  while(m--)
  {
    int a;
    cin>>a;
    cout<<d1[a]<<"\n";
  }
}

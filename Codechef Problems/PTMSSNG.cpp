#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,a,b;
  cin>>n;
  map<int,int>x,y;
  for(int i=0;i<((4*n)-1);i++)
  {
    cin>>a>>b;
    x[a]++;
    y[b]++;
  }
  int x1,y1;
  for(auto i:x)if(i.second%2!=0){x1=i.first;break;}
  for(auto i:y)if(i.second%2!=0){y1=i.first;break;}
  cout<<x1<<" "<<y1<<endl;
 }
}

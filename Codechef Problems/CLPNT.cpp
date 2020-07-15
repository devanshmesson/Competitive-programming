#include<bits/stdc++.h>
using namespace std;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>  ordered_set;
main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,ok=1,v;
  cin>>n;
  set<int>a;
  ordered_set s;
  for(int i=0;i<n;i++)
  {
    cin>>v;
    a.insert(v);
    s.insert(v);
  }
  int q,x,y,cnt=0;
  cin>>q;
  int sl;
  for(int i=0;i<q;i++)
  {
    cin>>x>>y;
    if(x==0 && y==0){cout<<0<<endl;continue;}
    int d=x+y;
    int flag=1,found;
    auto it=a.find(d);
    if(it!=a.end()){cout<<-1<<endl;continue;}
    flag=1;
    cout<<s.order_of_key(d)<<endl;
  }
 }
}

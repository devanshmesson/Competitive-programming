#include<bits/stdc++.h>
using namespace std;
main()
{  
  int n;
  cin>>n;
  int a[n+1];
  for(int i=1;i<=n;i++)cin>>a[i];

  int diff[n+2]={0};
  //make the difference array
  
  for(int i=1;i<=n+1;i++)
  {
    if(i==1)diff[i]=a[i];
    else diff[i]=a[i]-a[i-1];
  }

  //add x from L to R in q queries
  int q,l,r,x;
  cin>>q;
  for(int i=0;i<q;i++)
  {
    cin>>l>>r>>x;  //inputting range and the number to add
    diff[l]+=x;   //Range update in O(1)
    diff[r+1]-=x;
  }
  
  cout<<"Updated array"<<endl;
  for(int i=1;i<=n;i++)
  {
    if(i>1)diff[i]+=diff[i-1];
    a[i]=diff[i];
    cout<<a[i]<<" ";
  }
}

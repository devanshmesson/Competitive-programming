#include<bits/stdc++.h>
using namespace std;
#define pb push_back
main() 
{
  int t;
  cin>>t;
  while(t--)
  {
    int a,b;
    cin>>a>>b;
    if(a>=(2*b) || b>=(2*a)){cout<<min(a,b)<<endl;continue;}
    if(b>a)swap(a,b);
    int ans=a-b;  
    a=a-2*ans;
    b=b-ans;
    //after (a-b)steps a equals b
    int check=a-(a/3)*3;
    ans+=(check==2)+(a/3)*2;
    cout<<ans<<endl; 
  }
  return 0;
} 

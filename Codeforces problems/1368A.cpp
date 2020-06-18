#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,a,b;
    cin>>a>>b>>n;  
     if(a>n || b>n){cout<<0<<endl;continue;}
     map<int,int>f; 
     f[0] = max(a,b);   f[1] = a+b;
     if(f[1]>n){cout<<1<<endl;continue;}
     int cnt=1;
      int i=2;
      while(1)
      {
        f[i] = f[i-1] + f[i-2]; 
        cnt++;
        if(f[i]>n)break;
        i++;        
      }      
      cout<<cnt<<endl;
  }
 }

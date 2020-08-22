#include<bits/stdc++.h>
using namespace std;
main()
{ 
 int n,x,t;
 cin>>n>>x>>t;
 int ans=(n/x)+(n%x!=0);
 cout<<ans*t<<endl;
}

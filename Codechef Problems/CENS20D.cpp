#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
main()
{ 
 int t;
 cin>>t;
 while(t--)
 {
   int n;
   cin>>n;
   int a[n+1];
   int andi,cnt=0;
   for(int i=0;i<n;i++)
   {
    cin>>a[i];
   }
   for(int i=0;i<n;i++)
   {
    for(int j=i+1;j<n;j++)
    {
      andi=a[i]&a[j];
      if(andi==a[i])cnt++;
    }
   }
   cout<<cnt<<endl;
 }
}

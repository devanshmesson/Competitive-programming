#include<bits/stdc++.h>
using namespace std;
#define int long long int
main()
{ 
 int t;
 cin>>t;
 while(t--)
 {
   int n,grader,origsum;
   cin>>n;
   int ans=0,k=(1<<20);
   cout<<"1 "<<k<<endl;
   cin>>grader;
   origsum=grader-n*k;

   if(origsum%2==1)ans=1;

   for(int i=1;i<=19;i++)
   {
     cout<<"1 "<<(1<<i)<<endl;
     cin>>grader;

     int num=origsum-grader+(n*(1<<i));
     int den=(1<<(i+1));
     int num_of_ones=num/den;
     if(num_of_ones%2==1)ans+=(1<<i);
   }
   cout<<"2 "<<ans<<endl;
   cin>>grader;
   if(grader==-1)return 0;
 }
}

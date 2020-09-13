#include<bits/stdc++.h>
using namespace std;
main()
{ 
 int n,cap;
 cin>>n;
 int wt[n+1],val[n+1];
 for(int i=0;i<n;i++)cin>>wt[i];
 for(int i=0;i<n;i++)cin>>val[i];
 cin>>cap;
 
 int profit[n+1][cap+1]; //2-D Matrix for Bottom Up Approach.We take changing variables int rows and columns of 2D matrix

 //Initialization
 //for n=0 profit=0
 for(int i=0;i<=n;i++)profit[i][0]=0;
   
 //For w=0 profit=0
 for(int i=0;i<=cap;i++)profit[0][i]=0;
 
 //Starting for n=1 and w=1
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=cap;j++)
  {
    if(wt[i-1]<=j)
    {
      profit[i][j]=max(val[i-1]+profit[i-1][j-wt[i-1]],  //include the item
                 profit[i-1][j]);                  //don't include the item
    }
    else if(wt[i-1]>j)
    {
      profit[i][j]=profit[i-1][j]; //dont include the item
    }
  }
 }
 cout<<profit[n][cap]<<endl;
}

/*
Find minimum sum difference between sum of any two subsets.
 n=4
 array->2 3 4 6
 answer=1 [6 2] [3 4] 8-7=1
*/
#include<bits/stdc++.h>
using namespace std;
int subset(int weight[],int target,int n,int **dp)
{
  //Base case
  if(target==0)return 1;
  if(target!=0 && n==0)return 0;

  //if already computed
  if(dp[target][n]!=-1)return dp[target][n];
  //Choice diagram
  if(weight[n]<=target) //
  {
    return dp[target][n]=subset(weight,target-weight[n],n-1,dp) || subset(weight,target,n-1,dp); 
  }
  else
  {
    return dp[target][n]=subset(weight,target,n-1,dp);
  }
}

int main()
{
  int n,sum=0,target;
  cin>>n;
  int weight[n+1];
  for(int i=1;i<=n;i++){cin>>weight[i];sum+=weight[i];}
  cout<<sum<<endl;
  target=sum/2;
  int subsetsum1,subsetsum2;

  /*if sum=20
    then we would prefer to have 0 difference between sums of any two subsets.
    Hows that possible?
    sum of first subset=sum of second subset (10=10)
    if that's not possible as per the given array(if sum 10 does not exist in the array)
    then we would go with next minimum case that is 9 and 11. and so on.
    
    check from sum/2 to 0, if in between any sum got found in tha array we will take that sum becuase difference cant be more minimum.
  */


  for(int i=target;i>=0;i--)
  {
     int **dp=new int*[i+1];
     for(int row=1;row<=i;row++)
     {
      dp[row]=new int[n+1];
     }

     for(int j=1;j<=i;j++)for(int k=1;k<=n;k++)dp[j][k]=-1;

     if(subset(weight,i,n,dp)==1){subsetsum1=i;break;}
  }
  cout<<subsetsum1<<endl;
  subsetsum2=sum-subsetsum1;
  int difference=abs(subsetsum1-subsetsum2);
  cout<<"Minimum difference of any two subsets in given array:"<<difference<<endl;
  return 0;
}

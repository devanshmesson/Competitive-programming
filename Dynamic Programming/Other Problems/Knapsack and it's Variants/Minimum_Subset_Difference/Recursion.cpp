/*
Find minimum sum difference between sum of any two subsets.
 n=4
 array->2 3 4 6
 answer=1 [6 2] [3 4] 8-7=1
*/
#include<bits/stdc++.h>
using namespace std;

int ans=0;
int subset(int weight[],int target,int n)
{
  //Base case
  if(target==0)return 1;
  if(target!=0 && n==0)return 0;
  //Choice diagram
  if(weight[n]<=target) 
  {
    return subset(weight,target-weight[n],n-1) || subset(weight,target,n-1); 
  }
  else
  {
    return subset(weight,target,n-1);
  }
}
int main()
{
  int n,sum=0,target;
  cin>>n;
  int weight[n+1];
  for(int i=1;i<=n;i++){cin>>weight[i];sum+=weight[i];}
  target=sum/2;
  int subsetsum1,subsetsum2;
  for(int i=target;i>=0;i--)
  {
     if(subset(weight,i,n)==1){subsetsum1=i;break;}
  }
  subsetsum2=sum-subsetsum1;
  int difference=abs(subsetsum1-subsetsum2);
  cout<<"Minimum difference of any two subsets in given array:"<<difference<<endl;
  return 0;
}

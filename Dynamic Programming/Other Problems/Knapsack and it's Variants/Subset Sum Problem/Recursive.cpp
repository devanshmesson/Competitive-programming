/*
Given an array , Print Yes if there is a subset which has sum=given sum otherwise No.
INPUT:
5
2 3 7 8 10
target sum=11

OUTPUT:
Yes
*/
#include<bits/stdc++.h>
using namespace std;

bool knap(int weight[],int target,int n)
{
  //recursion ends at base case
  if(target==0)return 1;
  if(n==0 && target!=0)return 0;

  //code the choice diagram

  if(weight[n]<=target) //can include
  {
       return (knap(weight,target-weight[n],n-1)|| knap(weight,target,n-1));  /*include || not include*/  
       
       /*OR is done because answer is in O(NO) and 1(YES) form.*/
       /*if for that particular element (any of the choice-include/not include), answer=1 then we have to note that there exist a subset */
       /*Consider Situation, for inlcude , answer=1  for not inlcude, answer=0 then we have to note the case for inlusion of that element by (1 || 0) = 1  */
  }
  else //cannot include
  {
    return knap(weight,target,n-1);
  }
}
int main()
{
  int n;
  cin>>n;
  int weight[n+1],target;
  for(int i=1;i<=n;i++)cin>>weight[i];
  cin>>target;
  if(knap(weight,target,n)==1)cout<<"There exists a subset which has sum="<<target<<endl;
  else cout<<"No such subset exists which has sum="<<target<<endl;
  return 0;
}

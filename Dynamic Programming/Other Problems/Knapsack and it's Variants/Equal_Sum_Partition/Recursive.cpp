/*Partition the array such that sum of first partition = sum of second partition,print yes if its possible to partition the array in such a way */
#include<bits/stdc++.h>
using namespace std;

int equalsum(int weight[],int target,int n)
{
  //Base case
  if(target==0)return 1;
  if(target!=0 and n==0)return 0;

  //Choice Diagram
  if(weight[n]<=target) //can include the item
  {
    return equalsum(weight,target-weight[n],n-1) || equalsum(weight,target,n-1);
  }
  else 
  {
    return equalsum(weight,target,n-1);
  }

}
int main()
{
  int n;
  cin>>n;
  int weight[n+1],sum=0;
  for(int i=1;i<=n;i++){cin>>weight[i];sum+=weight[i];}
 
  /*two partitions in equal amount can only happen if sum of the array is even*/
  if(sum%2==1){cout<<"Array cannot be divided into two sets"<<endl;return 0;}

  /*we will apply subset sum problem here with target=sum/2 
    because if one subset is found then the other subset will
    contain rest of the remaining elements summing up as sum/2*/

   int target=sum/2;

   //target=0 so there exist null set return 1
   //target!=0 and n==0 return 0;

   if(equalsum(weight,target,n)==1)cout<<"Array can be divided into two sets"<<endl;
   else cout<<"Array cannot be divided into two sets"<<endl;
  
  return 0;
}

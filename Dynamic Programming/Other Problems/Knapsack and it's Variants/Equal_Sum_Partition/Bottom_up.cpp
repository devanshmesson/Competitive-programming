/*Partition the array such that sum of first partition = sum of second partition,print yes if its possible to partition the array in such a way */

#include<bits/stdc++.h>
using namespace std;
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

   int **dp=new int *[target+1]; //dynamically allocate row pointers to 
                              //further allocate columns

   for(int row=0;row<=target;row++)
   {
     dp[row]=new int[n+1];
   }

     //Base case in recursion = Initialization in the dp matrix

    //Base case 1 - target=0 then null set can be made so return 1
    for(int i=0;i<=n;i++)dp[0][i]=1;

    //Base case 2 - n==0 and target!=0 return 0
    for(int i=1;i<=target;i++)dp[i][0]=0;

   /*dp array will contain numbers like 0 and 1 ,0 means partition cannot be 
    possible for that subproblem, 1 means prtition is possible for that subproblem
   */

   for(int i=1;i<=target;i++)
   {
     for(int j=1;j<=n;j++)
     {
       if(weight[j]<=i) //can include item
       {
         dp[i][j]=dp[i-weight[j]][j-1] || dp[i][j-1]; /*include || not-include*/
       }
       else //cannot include the item
       {
        dp[i][j]=dp[i][j-1]; //never include the item
       }
     }
   }
   if(dp[target][n]==1)cout<<"Array can be divided into two sets"<<endl;
   else cout<<"Array cannot be divided into two sets"<<endl;
   return 0;
}

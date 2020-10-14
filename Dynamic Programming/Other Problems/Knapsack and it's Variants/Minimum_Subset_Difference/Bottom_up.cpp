/*
Find minimum sum difference between sum of any two subsets.
 n=4
 array->2 3 4 6
 answer=1 [6 2] [3 4] 8-7=1
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,sum=0,target;
  cin>>n;
  int weight[n+1];
  for(int i=1;i<=n;i++){cin>>weight[i];sum+=weight[i];}
  target=sum/2;
  int subsetsum1,subsetsum2;

 /* if sum=20
    then we would prefer to have 0 difference between sums of any two subsets.
    Hows that possible?
    sum of first subset=sum of second subset (10=10)
    if that's not possible as per the given array(if sum 10 does not exist in the array)
    then we would go with next minimum case that is 9 and 11. and so on.
    
    check from sum/2 to 0, if in between any sum got found in tha array we will take that sum becuase difference cant be more minimum.
  */


     int **dp=new int*[target+1];
     for(int row=0;row<=target;row++)dp[row]=new int[n+1];
     
      //Base case in recursion =Initialization in Bottom up dp

     //base case 1:target=0 then return 1
     for(int i=0;i<=n;i++)dp[0][i]=1;

      //base case 2: if target!=0 and n==0 then return 0
      for(int i=1;i<=target;i++)dp[i][0]=0;
      
      for(int i=1;i<=target;i++)
      {
        for(int j=1;j<=n;j++)
        {
          if(weight[j]<=i)
          {
            dp[i][j]=dp[i-weight[j]][j-1] || dp[i][j-1];
          }
          else 
          {
            dp[i][j]=dp[i][j-1];
          }
           if(dp[i][n]==1)subsetsum1=i;
           //Last row of the matrix will give us info about all sums between 1 and target such that 
           //if there is a subset present in array whose sum = that particular column(sum).
           //we will take the maximum sum which has dp[sum][n]=1 to minimize the difference.
        }
      }
  
  subsetsum2=sum-subsetsum1;
  int difference=abs(subsetsum1-subsetsum2);
  cout<<"Minimum difference of any two subsets in given array:"<<difference<<endl;
  return 0;
}

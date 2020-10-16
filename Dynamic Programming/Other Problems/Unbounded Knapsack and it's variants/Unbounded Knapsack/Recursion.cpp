/*
 Unbounded Knapsack!
 Given 'n' number of items with their weight and value.
 Given a knapsack with a 'capacity'.

 Task-Put items in the knapsack such that profit is maximised keeping in note that
 weight of items must not exceed capacity of knapsack.Particular item can be put in the knapsack
 any number of times(infinite quantity).

 Example-
 n=8
 weight array-1 2 3 4  5  6  7  8
 value  array-1 5 8 9 10 17 17 20

 Maximum Profit=22

item : quantity
  6  : 1    =17
  2  : 1    =5
  ------------
            =22
*/
#include<bits/stdc++.h>
using namespace std;

int unbounded(int weight[],int val[],int capacity,int n)
{
  //base case
  if(n==0 || capacity==0)return 0;

  /*
   CHOICE DIAGRAM

   Case:1 - Item can be included 
   #Include item one or more times (stay on that index till capacity is full)
   #dont include the item (move to next item)

   Case:2 - Item cannot be included as it exceeds the capacity
  */

  //Simply code the choice diagram

  if(weight[n]<=capacity) //Case:1
  {
    return max(val[n]+unbounded(weight,val,capacity-weight[n],n) //include the item multiple times (stayed on that index)
                     ,unbounded(weight,val,capacity,n-1)); //skip this item,so move to next item(index)
  }
  else//Case:2
  {
    return unbounded(weight,val,capacity,n-1); //skip this item,so move to next item(index)
  }
 
}

int main()
{
  int n;
  cin>>n;
  int weight[n+1],val[n+1];
  for(int i=1;i<=n;i++)cin>>weight[i];
  for(int i=1;i<=n;i++)cin>>val[i];
  int capacity;
  cin>>capacity;
 
  /*
   Item can be put multiple times in knapsack;

   if : item is to be put one more time - dont traverse the array,stay on that index
   if : item is not to be put in knapsack - traverse the array further,go to next index

   do the same until we traversed whole array
  */

  cout<<unbounded(weight,val,capacity,n)<<endl;
  return 0;
}

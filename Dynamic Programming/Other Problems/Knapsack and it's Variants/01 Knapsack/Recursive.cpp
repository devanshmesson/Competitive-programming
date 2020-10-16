/*
This is a Recursive Approach of 0/1 Knapsack Problem.
A bag with a weight capacity,items and their weights and costs are available to us.
We have to put items in the bag such that we Profit is MAXIMIZED and Bag does not exceed its weight capacity.

In this Code, We are deciding whether we should incude a particular item or not.
*/
#include<bits/stdc++.h>
using namespace std;

int knapsack(int *wt,int *val,int cap,int n)
{
    //Think of the base case 
    //Base case is the smallest valid input in the problem
    //Smallest Valid Input for weight is 0
    //Smallest Valid input for value is 0

    if(n==0 || cap==0)return 0;

    //Just Code the Choice Diagram
    if(wt[n-1]<=cap)
    {
        return max(val[n-1]+knapsack(wt,val,cap-wt[n-1],n-1),  //include the Item
                   knapsack(wt,val,cap,n-1));     //Dont include the item
    }
    else 
    {
        return knapsack(wt,val,cap,n-1);  //Item cannot be inlcluded as its Exceeding knapsack capacity
    }
}
main()
{ 
 int n;
 cin>>n;
 int wt[n+1],val[n+1],cap;
 for(int i=0;i<n;i++)cin>>wt[i];
 for(int i=0;i<n;i++)cin>>val[i];
 cin>>cap;
 int maxprofit=knapsack(wt,val,cap,n);
 cout<<maxprofit<<endl;
}

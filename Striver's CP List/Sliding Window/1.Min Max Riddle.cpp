//Link - 
#include <bits/stdc++.h>
using namespace std;

// Complete the riddle function below.
vector<long> riddle(vector<long> arr) 
{
     int n=arr.size();
     vector<long>ans(n,-1);
     //finding first maller element in right direction
     stack<long>right;
     int* rightnse=new int[n];
     int* leftnse=new int[n];
     for(int i=0;i<n;i++)
     {
         if(s.empty()==true)s.push(i);
   else
   {
     if(arr[i]>=arr[s.top()])s.push(i);
     else 
     {
       while(s.empty()==false && arr[i]<arr[s.top()])
       {
        int top=s.top();
        rightnse[top]=i;
        s.pop();
       }
       s.push(i);
     }
   } 
     }
     while(s.empty()==false)
     {
         rightnse[s.top()]=n;
         s.pop();
     }
     
     //finding first smaller element in left direction
      for(int i=n-1;i>=0;i--)
     {
         if(s.empty()==true)s.push(i);
   else
   {
     if(arr[i]>=arr[s.top()])s.push(i);
     else 
     {
       while(s.empty()==false && arr[i]<arr[s.top()])
       {
        int top=s.top();
        leftnse[top]=i;
        s.pop();
       }
       s.push(i);
     }
   } 
     }
     while(s.empty()==false)
     {
         leftnse[s.top()]=-1;
         s.pop();
     }
     for(int i=0;i<n;i++)
     {
        int len=rightnse[i]-leftnse[i]-1;
        if(ans[len-1]<arr[i])ans[len-1]=arr[i];
     }
     for(int i=n-2;i>=0;i--)
     {
      ans[i]=max(ans[i],ans[i+1]);
     }
     return ans;

}

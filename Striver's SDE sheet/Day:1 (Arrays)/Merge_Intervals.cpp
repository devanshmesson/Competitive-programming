/*
Problem Link - https://leetcode.com/problems/merge-intervals/
*/

class Solution 
{
 public:
 #define pb push_back
struct interval
{
  int val1,val2;   
};

void merge_arrays(int l,int mid,int r,vector<vector<int>>&interval)
{
    struct interval left[r-l+1],right[r-l+1];
    int p=0,q=0;
    for(int i=l;i<=mid;i++)
    {
      left[p].val1=interval[i][0];
      left[p].val2=interval[i][1];
      p++;
    }
    for(int i=mid+1;i<=r;i++)
    {
      right[q].val1=interval[i][0];
      right[q].val2=interval[i][1];
      q++;
    }
    
    int i=0,j=0,in=l;

    while(i<p && j<q)
    {
      if(left[i].val1<right[j].val1)
      {
          interval[in][0]=left[i].val1;
          interval[in][1]=left[i].val2;
          i++;
      }
      else
      {
          interval[in][0]=right[j].val1;
          interval[in][1]=right[j].val2;
          j++;
      }
      in++;
    }
    
    while(i<p)
    {
        interval[in][0]=left[i].val1;
        interval[in][1]=left[i].val2;
        in++;
        i++;
    }
    
    while(j<q)
    {
        interval[in][0]=right[j].val1;
        interval[in][1]=right[j].val2;
        in++;
        j++;
    }  
}

void mergesort(vector<vector<int>>&interval,int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(interval,l,mid);
        mergesort(interval,mid+1,r);
        merge_arrays(l,mid,r,interval);
    }
}
vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
  int intervalsSize=intervals.size();
  if(intervalsSize==1)return intervals;
  mergesort(intervals,0,intervalsSize-1);
  vector<vector<int>>inter;
  for(int i=1;i<intervalsSize;i++)
  {
     if(i>=1 && intervals[i][0]<=intervals[i-1][1])
     {
         intervals[i][1]=max(intervals[i][1],intervals[i-1][1]);
         intervals[i][0]=intervals[i-1][0];
     }
     else
     {
         inter.pb(intervals[i-1]);
     }
  }
     inter.pb(intervals[intervalsSize-1]);
     return inter;
    }
};

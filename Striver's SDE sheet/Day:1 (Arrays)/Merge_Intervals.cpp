/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
struct interval
{
  int val,ind;   
};

void merge_arrays(int l,int mid,int r, int intervalsSize,int **intervals)
{
    struct interval left[intervalsSize],right[intervalsSize];
    int p=0,q=0;
    for(int i=l;i<=mid;i++)
    {
      left[p].val=intervals[i][0];
      left[p].ind=i;
      p++;
    }
    for(int i=mid+1;i<=r;i++)
    {
      right[q].val=intervals[i][0];
      right[q].ind=i;
      q++;
    }
    
    int i=0,j=0,ind=l;
    while(i<p && j<q)
    {
      if(left[i].val<=right[j].val)
      {
          intervals[ind][0]=left[i].val;
          intervals[ind][1]=intervals[left[i].ind][1];
          i++;
      }
      else
      {
          intervals[ind][0]=right[j].val;
          intervals[ind][1]=intervals[right[j].ind][1];
          j++;
      }
      ind++;
    }
    
    while(i<p)
    {
        intervals[ind][0]=left[i].val;
        intervals[ind][1]=intervals[left[i].ind][1];
        ind++;
        i++;
    }
    
    while(j<q)
    {
        intervals[ind][0]=right[j].val;
        intervals[ind][1]=intervals[right[j].ind][1];
        ind++;
        j++;
    }       
}

void mergesort(int** intervals,int l,int r,int intervalsSize)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(intervals,l,mid,intervalsSize);
        mergesort(intervals,mid+1,r,intervalsSize);
        return merge_arrays(l,mid,r,intervalsSize,intervals);
    }
    
}
int max(int a,int b)
{
    if(a>=b)return a;
    else return b;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
  //mergesort(intervals,0,intervalsSize-1,intervalsSize);
  int top=0;
  int **ans=(int**)malloc((intervalsSize+10)*sizeof(int));
  for(int i=0;i<intervalsSize;i++)
  {
      ans[i]=(int*)malloc(2*sizeof(int));
  }
    
   int in=0;

  // for(int i=1;i<intervalsSize;i++)
  // {
  //    if(intervals[i][0]<=intervals[i-1][1])
  //    {
  //        intervals[i][1]=max(intervals[i][1],intervals[i-1][1]);
  //        intervals[i][0]=intervals[i-1][0];
  //    }
  //    else
  //    {
  //        ans[in][0]=intervals[i-1][0];
  //        ans[in][1]=intervals[i-1][1];
  //        in++;
  //    }
  // }
    return intervals;
    // free(ans);
    
    
}

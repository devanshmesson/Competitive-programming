int merge_sorted_arrays(int l,int mid,int r)
{ 
   //make two arrays to store l..mid and mid+1..r
  // cout<<"\n\nMERGE SORTED ARRAYS "<<l<<" "<<mid<<" "<<r<<"\n\n";
  int n=mid-l+1,m=r-(mid+1)+1;
  int left[n],right[m];

  
  for(int i=l;i<=mid;i++)
  {
    left[i-l]=hashes[i];
  }
  for(int i=mid+1;i<=r;i++)
  {
    right[i-(mid+1)]=hashes[i];
  }


  int i=0,j=0,k=l;

  while(i<n && j<m)
  {
    if(left[i]<right[j])
    {
      hashes[k++]=left[i];
      i++;
    }
    else 
    {
      hashes[k++]=right[j];
      j++;
    }
  }

  while(i<n)hashes[k++]=left[i++];
  while(j<m)hashes[k++]=right[j++];
}

int merge_sort(int l,int r)
{
  int mid=(l+r)/2;
  if(l<r)
  {
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    merge_sorted_arrays(l,mid,r);
  }
}

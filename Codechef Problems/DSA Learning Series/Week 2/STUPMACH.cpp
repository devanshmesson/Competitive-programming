/*
Problem-Given n boxes with their capacities to hold coins and you have to select a box and fill one coin in each of the boxes which are previous to this box
        including this box but capacity of any box should not be overloaded.
Time Complexity-O(n)
Approach-If a box with small quantity comes before a box with a large quantity then we cant fill the whole box of the larger quantity as small box's capacity is full
         So we cant select that box(with large quantity now)
        -So Run a loop from 0 to n-2 and if a small number comes before a large number then change that large number to small number and add all these values.
*/
#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
      if(a[i]>=a[i+1])ans+=a[i];
      else if(a[i]<a[i+1])
      {
        a[i+1]=a[i];
        ans+=a[i];
      }
    }
    ans+=a[n-1];
    cout<<ans<<endl;
  }
}

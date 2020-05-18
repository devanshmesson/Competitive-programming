// All subsets possible in an array through recursion
#include<bits/stdc++.h>
using namespace std;
vector<int>subset;
int sear(int a[],int k,int n)
{
    if (k == n+1)
    {
     for(int i=0;i<subset.size();i++)cout<<subset[i]<<" ";
     cout<<endl;
    }
    else
    {
    	 subset.push_back(a[k]);
         sear(a,k+1,n);
         subset.pop_back();
         sear(a,k+1,n);
    }
}
int32_t main()
{
	
  int n;
	int n;
  cin>>n;
   int a[n+1];
   for(int i=1;i<=n;i++)cin>>a[i];
   sear(a,1,n);
}

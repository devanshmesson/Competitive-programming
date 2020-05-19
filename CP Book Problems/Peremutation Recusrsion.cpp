#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<map>
#include <algorithm>
//#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define freopen //comment
#endif
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

//#define int long long int
#define mk make_pair
int n;
vector<int>perm;

int sear(int n,int chosen[])
{
    if (perm.size() == n) 
    {
     for(int i=0;i<perm.size();i++)cout<<perm[i]<<" ";
     cout<<endl;
    } 
    else 
    { 
    	for (int i = 1; i <= n; i++) 
    	{ 
    	  
    	   if (chosen[i]) continue; 
    	   chosen[i] = true; 
    	   perm.push_back(i); 
    	   sear(n,chosen);
    	   chosen[i] = false; 
    	   perm.pop_back();
    	}
    }

}
int32_t main()
{
	freopen
	io
	int n;
   cin>>n;
   int chosen[n+1]={0};
   int a[n+1];
   for(int i=1;i<=n;i++)cin>>a[i];
   sear(n,chosen);
}

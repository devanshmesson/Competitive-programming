#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
int ans=0;
int sear(int x,int n,unordered_map<int,int>left,unordered_map<int,int>rit,unordered_map<int,int>col)
{
	if(x==n+1){ans++;}

	for(int y=1;y<=n;y++)
    { 
    	if(col[y] || left[x+y] || rit[y-x+n])continue;
    	col[y]=1;
    	left[x+y]=1;
    	rit[y-x+n]=1;
    	sear(x+1,n,left,rit,col);
    	col[y]=0;
    	left[x+y]=0;
    	rit[y-x+n]=0;
    }
   return ans;

}



int32_t main()
{
	freopen
	io
	int n;
   cin>>n;
   unordered_map<int,int>left;
   unordered_map<int,int>rit;
   unordered_map<int,int>col;
   int a=sear(1,n,left,rit,col);
   cout<<a<<endl;
}                                               

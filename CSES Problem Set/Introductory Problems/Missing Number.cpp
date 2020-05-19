#include<bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int

int32_t main()
{
	io
	//freopen
	int n;
   cin>>n;
   vector<int>v;
   int a;
   for(int i=0;i<n-1;i++){cin>>a;v.push_back(a);}
   	sort(v.begin(),v.end());
   a=1;

    for(int i=0;i<n-1;i++)
    {
       if(v[i]!=a){break;}
       a++;
    }
    cout<<a<<endl;
}                                               

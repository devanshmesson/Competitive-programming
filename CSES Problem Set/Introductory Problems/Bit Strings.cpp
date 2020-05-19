#include<bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
int mod=1e9+7;

int power(int x, unsigned int y, int p)  
{  
    int res = 1;      
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0)  
    {  
        if (y & 1) res = (res*x) % p;  
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
}  

int32_t main()
{
	io
	//freopen
	int n;
	cin>>n;
	cout<<power(2,n,mod)<<endl;
}        


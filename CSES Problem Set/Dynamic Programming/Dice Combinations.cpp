#include <iostream>
 
using namespace std;
//int N=100000;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int n;
    cin>>n;
    int d[n+100];
    d[0]=1;
    d[1]=1;
    d[2]=2;
    d[3]=4;
    d[4]=8;
    d[5]=16;
    if(n==1){cout<<1<<endl;return 0;}
    else if(n==2){cout<<2<<endl;return 0;}
 
    for(int i=6;i<=n;i++)
    {
        d[i]=d[i-1]%1000000007+d[i-2]%1000000007+d[i-3]%1000000007+d[i-4]%1000000007+d[i-5]%1000000007+d[i-6]%1000000007;
    }
 
 
    cout<<d[n]%(1000000007)<<endl;
 
 
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int sum(int a)
{
    int res=0,k;
    while(a!=0)
    {
        k=a%10;
        a/=10;
        res+=k;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(1)
    {
        if(sum(n)%4==0){cout<<n<<endl;break;}
        n++;
    }
    
    return 0;
}

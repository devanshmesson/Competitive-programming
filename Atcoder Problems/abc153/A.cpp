#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int h,a,cnt=0;
    cin>>h>>a;
    while(1)
    {
        h-=a;
        cnt++;
        if(h<=0)break;
    }
    cout<<cnt<<endl;
    return 0;
}

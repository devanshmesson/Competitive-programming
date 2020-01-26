#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int h,cnt=1,i=1;
    cin>>h;
        while(h!=1)
        {
            h=h/2;
            cnt+=i*2;
            i=i*2;
        }
        //cout<<cnt<<endl;
        //sum=(1 << (cnt)) - 1;
        cout<<cnt<<endl;
        return 0;
}

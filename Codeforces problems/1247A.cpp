#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int a,b,flag=1;
    cin>>a>>b;
    if(a<=b)
    {
        if(b-a==1)
        {
            cout<<a<<"9"<<" "<<b<<"0"<<endl;
            flag=0;
        }
        if(b-a==0)
        {
            cout<<a<<"1"<<" "<<b<<"2"<<endl;
            flag=0;
        }
    }
    else if(a==9 && b==1)
    {
        cout<<a<<"9"<<" "<<b<<"00"<<endl;
        flag=0;
    }
    if(flag==1)cout<<"-1"<<endl;
    return 0;
}

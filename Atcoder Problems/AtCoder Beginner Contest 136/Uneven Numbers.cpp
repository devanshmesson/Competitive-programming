#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,t,k,cnt=0;
    cin>>n;
    t=n;
    while(t!=0)
    {
        k=t%10;
        t=t/10;
        cnt++;
    }
    if(cnt==1)cout<<n<<endl;
    else if(cnt==2)cout<<9;
    else if(cnt==3)cout<<n-100+1+9<<endl;
    else if(cnt==4)cout<<900+9<<endl;
    else if(cnt==5)cout<<n-10000+1+900+9<<endl;
    else if(cnt==6)cout<<90000+900+9;
    return 0;
}

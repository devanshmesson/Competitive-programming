#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,flag=0,mid;
    cin>>a>>b;
     mid=(a+b)/2;
     if(fabs(a-mid)==fabs(b-mid)) {flag=1;}
   if(flag==0) cout<<"IMPOSSIBLE"<<endl;
   else cout<<mid<<endl;
    return 0;
}

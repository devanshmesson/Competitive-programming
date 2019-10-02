#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,cnt=0,sum=1;
    cin>>a>>b;
    while(1)
    {
        if(sum>=b)break;
        sum--;
        cnt++;
        sum+=a;
    }
cout<<cnt<<endl;
    return 0;
}

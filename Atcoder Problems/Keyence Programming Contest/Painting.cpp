#include <bits/stdc++.h>

using namespace std;

int main()
{
    float h,w,n;
    cin>>h>>w>>n;
    if(h>w)cout<<ceil(n/h)<<endl;
    else cout<<ceil(n/w)<<endl;
    return 0;
}

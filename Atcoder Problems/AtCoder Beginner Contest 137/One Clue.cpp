#include <bits/stdc++.h>

using namespace std;

int main()
{
   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int k,x;
    cin>>k>>x;
    for(int i=x-k+1;i<=x+k-1;i++)
    {
        cout<<i<<" ";
    }
    return 0;
}

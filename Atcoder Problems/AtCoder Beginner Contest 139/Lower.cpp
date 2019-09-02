#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,maxm=0,cnt=0;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }

    for(int i=0;i<n-1;i++)
    {
        if(v[i]>=v[i+1]) cnt++;
        else cnt=0;
        if(cnt>maxm)
        {
            maxm=cnt;
        }
    }
    cout<<maxm;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d;
    float x,m,a;
    cin>>n;
    vector<float> v;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    x=(v[0]+v[1])/2;
    m=x;
    for(int i=2;i<n;i++)
    {
       m=(m+v[i])/2;
    }
    cout<<m;
}

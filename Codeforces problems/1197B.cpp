#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m=INT_MIN,flag=1;
    cin>>n;
    vector<int>v;
    int a,in;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
        if(m<a)
        {
            m=a;
            in=i;
        }
    }
    for(int i=0;i<in;i++)
    {
        if(v[i]>=v[i+1]){flag=0;break;}
    }
    for(int i=in;i<n-1;i++)
    {
        if(v[i]<=v[i+1]){flag=0;break;}
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

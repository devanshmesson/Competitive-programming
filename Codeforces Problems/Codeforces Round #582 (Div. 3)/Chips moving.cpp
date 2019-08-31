#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,cnt=0;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
        if(a%2==0)
        {
            cnt++;
        }
    }
    cout<<min(cnt,n-cnt);

}

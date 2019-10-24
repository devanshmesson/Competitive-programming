#include<bits/stdc++.h>
using namespace std;
int main()
{
    #define int long long int
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int k,v,a;
        int sum=0.0,avg=0,n;
        cin>>n>>k>>v;
        vector<int>vec;
        for(int i=0;i<n;i++){cin>>a;vec.push_back(a);}
        for(int i=0;i<n;i++)
        {
            sum+=vec[i];
        }

        if((v*(n+k)-sum)%k==0 && ((v*(n+k)-sum)/k)>0 )cout<<(v*(n+k)-sum)/k<<endl;
        else cout<<"-1"<<endl;

    }
    return 0;
}

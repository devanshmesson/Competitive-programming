#include <bits/stdc++.h>
using namespace std;
int main()
{
   #define int long long int
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,cnt=1,flag=1,c=0;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){cin>>a; v.push_back(a);}

        for(int i=1;i<n;i++)
        {
            flag=1;
            for(int j=max(i-5,c);j<i;j++)
            {
                if(v[i]>=v[j]){flag=0;break;}
            }
            if(flag==1)cnt++;
        }
        cout<<cnt<<endl;

    }
    return 0;
}

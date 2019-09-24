#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie();cout.tie(0);
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int a,b,sum=0,tp=0,k=0,ans=0;
        cin>>a>>b;
        vector<int> v;
        sum=a+b;
        tp=sum;

        while(tp!=0)
        {
          k=tp%10;
          v.push_back(k);
          tp=tp/10;
        }
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            k=v[i];
           if(k==0||k==9||k==6)ans+=6;
          else if(k==1)ans+=2;
          else if(k==2||k==3||k==5)ans+=5;
          else if(k==4)ans+=4;
          else if(k==7)ans+=3;
          else if(k==8)ans+=7;
        }

    cout<<ans<<endl;
    }
    return 0;
}

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
        int n,a,b,in,flag=1,f=1,b1;
        cin>>n;
        vector<int>v,h;
        int c[n+1]={0};
        for(int i=0;i<n;i++)
        {
            f=1;
            cin>>a;
            v.push_back(a);
            h.clear();
            for(int j=0;j<a;j++)
            {
                cin>>b;
                h.push_back(b);
            }
            for(int g=0;g<a;g++)
            {
                if(c[h[g]]!=1){f=0;c[h[g]]=1;break;}
                else continue;
            }
            if(f==1){b1=i;}
            h.clear();
        }
      
        for(int i=1;i<=n;i++) if(c[i]!=1){flag=0;in=i;break;}
        
        if(flag==1)cout<<"OPTIMAL"<<endl;
        else
        {
          cout<<"IMPROVE"<<endl;
          cout<<b1+1<<" "<<in<<endl;
        }

    }
}

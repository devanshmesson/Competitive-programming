#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int l,r,x,t,k,flag=1;
    cin>>l>>r;
    vector<int> v,h;
    for(int i=l;i<=r;i++)
    {
        flag=1;
        t=i;
        v.clear();
        h.clear();
       // cout<<t<<endl;
        while(t!=0)
        {
            k=t%10;
            t=t/10;
            v.push_back(k);
            h.push_back(k);
            //cout<<k<<" ";
        }
        int s=v.size();
        int s1=h.size();
        sort(v.begin(),v.end());
      //  for(int j=0;j<s;j++)cout<<v[j]<<" ";
        for(int k=0;k<s;k++)
        {
            if(v[k]==v[k+1]){flag=0;break;}
        }
        if(flag==1)
        {
            for(int g=s1-1;g>=0;g--)
            {
                cout<<h[g];
            }
            break;
        }
        else continue;
 
    }
    if(flag==0)cout<<"-1"<<endl;
    return 0;
}

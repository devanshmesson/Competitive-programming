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
    int n,k,ar,a,b,flag=1;
    cin>>n>>k;
    vector<int> v;
    vector<pair<int,int> > vec;
    for(int i=0;i<n;i++)
    {
        cin>>ar;
        v.push_back(ar);
    }
    for(int i=0;i<n;i++)
    {
        vec.push_back(make_pair(i%n,n-(i%n)-1));
        if(i%n==n-(i%n)-1)
        {
            if(k>=(i%n)+1)v[vec[i%n].first]=0;
        }
    }

//cout<<endl<<endl;
    int stop=k%(n*3);

    if(stop==0)flag=0;

    else
    {
      for(int i=0;i<n*3;i++)
      {
          a=v[vec[i%n].first]; b=v[vec[i%n].second];
          v[vec[i%n].first]=a^b;
         // cout<<vec[i%n].first<<endl<<"-->"<<v[vec[i%n].first]<<" "<<endl;
          if(stop==i+1){flag=0;break;}
      }
    }
    //cout<<endl<<endl;
    if(flag==0)
    {
        for(int i=0;i<n;i++)
        {
            cout<<v[i]<<" ";
        }
    }
    cout<<endl;
    continue;
    }
}

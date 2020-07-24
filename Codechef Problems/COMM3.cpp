#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int r,a,b;
    cin>>r;
    r*=r;
    vector<pair<int,int>>v;
    int s=3;
    while(s!=0)
    {
      cin>>a>>b;
      v.pb({a,b});
      s--;
    }
    int cnt=0,s3,ok=1,s4;
    for(int i=0;i<3;i++)
    {  
      ok=1;
      for(int j=i+1;j<3;j++)
      {
        int s1=abs(v[j].first-v[i].first);
        int s2=abs(v[i].second-v[j].second);
        s1*=s1;
        s2*=s2;

        if(s1+s2>r)ok=0;
        if(ok==0)
        {
        if(i==0 &&  j==1)cnt=2;
        else if(i==0 && j==2)cnt=1;
        else if(i==1 && j==2)cnt=0;

            s3=abs(v[i].second-v[cnt].second);
            s4=abs(v[i].first-v[cnt].first);
            s3*=s3;
            s4*=s4;
            if(s4+s3<=r)
            {
              s3=abs(v[j].second-v[cnt].second);
              s4=abs(v[j].first-v[cnt].first);
              s3*=s3;
              s4*=s4;
              if(s4+s3<=r)ok=1;
            }
        }
        if(ok==0)break;
      }
      if(ok==0)break;
    }
    if(ok)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
}

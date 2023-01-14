#include<bits/stdc++.h>
using namespace std;
#define int long long int

#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin);freopen("out.txt","w",stdout);
#else
#define freopen //commentb
#endif


signed main()
{
  freopen
  int  t;
  cin>>t;
  while(t--)
  {
    string s,s1,s2,s3;
    cin>>s;
    int n=s.size();
    bool flag=true;
    for(int i=0;i<n;i++)
    {
      for(int j=i+1;j<n;j++)
      {
        s1 = s.substr(0,i+1);
        s2 = s.substr(i+1,j-i);
        s3 = s.substr(j+1,n-1-j);
        if((s2>=s1 && s2>=s3)||(s2<=s1 && s2<=s3))
        {
          flag=false;
          break;
        }
      }
      if(flag==false)
        {
          cout<<s1<<" "<<s2<<" "<<s3<<endl;
          break;
        }
    }

  }
}




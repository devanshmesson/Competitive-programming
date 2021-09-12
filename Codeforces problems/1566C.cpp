#include<bits/stdc++.h>
using namespace std;
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define pb push_back
#define int long long int
main()
{
//   freopen
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int ans=0;
    for(int i=0;i<n;)
    {
      if(a[i]!=b[i]){ans+=2; i++;}
      else if(i+1<n)
      {
      
        if(a[i]==b[i] && a[i]=='1' && a[i+1]==b[i+1] && a[i+1]=='0')
        {
          ans+=2;
          i+=2;
        }
        else if(a[i]==b[i] && a[i]=='0' && a[i+1]==b[i+1] && a[i+1]=='1')
        {
          ans+=2;
          i+=2;
        }
        else if(a[i]==b[i] && a[i]=='0' && a[i+1]==b[i+1] && a[i+1]=='0')
        {
          ans++;
          i++;
        }
        else if(a[i]==b[i] && a[i]=='1' && a[i+1]==b[i+1] && a[i+1]=='1')
        {
          i++;
        }
        else if(a[i]==b[i] && a[i]=='0'){ans++;i++;}
        else if(a[i]==b[i] && a[i]=='1'){i++;}
      }
      else if(a[i]==b[i] && a[i]=='0'){ans++;i++;}
      else {i++;}

    }

    cout<<ans<<endl;
  }
}

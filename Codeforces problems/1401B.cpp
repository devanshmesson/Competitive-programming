#include<bits/stdc++.h>
using namespace std;
main()
{ 
 int t;
 cin>>t;
 while(t--)
 {
  int zero,one,two;
  int ar[3],br[3];
  cin>>zero>>one>>two;
  ar[0]=zero;
  ar[1]=one;
  ar[2]=two;
  int zero1,one1,two1;
  cin>>zero1>>one1>>two1;
  br[0]=two1;
  br[1]=zero1;
  br[2]=one1;

  int ans=0;
  
  int ss=min(ar[2],br[2]);
  ans+=2*min(ar[2],br[2]);
  ar[2]-=ss;
  br[2]-=ss;
  
  int tem=min(ar[2],br[0]);
  ar[2]-=tem;
  br[0]-=tem;
  
   if(br[1]>=ar[1] || br[2]>=ar[1] || (br[1]+br[2])>=ar[1])
  {
    cout<<ans<<endl;
    continue;
  }

    int temp=min(ar[1],br[1]);
    ar[1]-=temp;
    br[1]-=temp;
    temp=min(ar[1],br[2]);
    ar[1]-=temp;
    br[2]-=temp;
    temp=min(ar[0],br[0]);
    ar[0]-=temp;
    br[0]-=temp;
    ans-=2*min(ar[1],br[0]);
    cout<<ans<<endl;
 }
}

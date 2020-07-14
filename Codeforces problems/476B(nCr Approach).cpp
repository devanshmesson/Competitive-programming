#include<bits/stdc++.h>
using namespace std;
int ncr(int n,int r)
{
  r=min(r,n-r);
  int a=1,b=1,gcd;
  if(r==0)return 1;
  while(r)
  {
    a*=n;
    b*=r;
    gcd=__gcd(a,b);
    a/=gcd;
    b/=gcd;
    n--;
    r--;
  }
  return a/b;

}
int main()
{
 string s,t;
 cin>>s>>t;
 int sz=s.size(),val=0,vali=0,q=0;
 for(int i=0;i<sz;i++)
  {
    if(s[i]=='+')val++;
    else val--;
  }
  for(int i=0;i<sz;i++)
  {
   if(t[i]=='+')vali++;
   else if(t[i]=='-')vali--;
   else q++;
  }
  if(q==0 && vali==val){cout<<"1.000000000"<<endl;return 0;}
  else if(q==0 && vali!=val || (q<abs(val-vali))){cout<<"0.000000000"<<endl;return 0;}
 

  int ans=ncr(q,(q+abs(val-vali))/2);
  int tot=1<<q;
  double prob=(float)ans/(float)tot;
  printf("%.9f\n",prob);
}

/*
Learning in this problem : 
While writing a loop, always keep in mind that write the code in side the loop in such a way that it is correct 
in a situation when the loop is running for the first time.
*/
#include<bits/stdc++.h>
using namespace std;
main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;

  if(k==0){cout<<"YES"<<endl;continue;}
  if(n==2){cout<<"NO"<<endl;continue;}
  
  int i=0,j=n-1,c=0,ok=-1;
  while(1)
  {
    if(s[i]!=s[j]){ok=0;break;}
    c++;
    if(c==k){ok=1;break;}
    i++; j--;
    if(j-i<=1)break;
  } 
  if(ok==1){cout<<"YES"<<endl;}
  else cout<<"NO"<<endl;
 } 
}

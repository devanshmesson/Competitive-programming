#include<bits/stdc++.h>
using namespace std;

bool powerof2 (int x) {  return x && (!(x&(x-1)));}  

bool isprime(int n)
{
  if(n==2 || n==3)return 1;
  if(n%2==0 || n%3==0 || n==1)return 0;
  for(int i=5;i*i<=n;i+=6)
  {
    if(n%i==0 || n%(i+2)==0)return 0;
  }
  return 1;
}
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    if(n==1)cout<<"FastestFinger"<<endl;
    else if(powerof2(n) && n>2){cout<<"FastestFinger"<<endl;}
    else if(n%2!=0){cout<<"Ashishgup"<<endl;}
    else if(n%4==0){cout<<"Ashishgup"<<endl;}
    else if(isprime(n/2))cout<<"FastestFinger"<<endl;
    else cout<<"Ashishgup"<<endl;
  }
 }

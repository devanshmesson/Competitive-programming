#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,s,t,mi,ma;
        cin>>n>>s>>t;
        if(s>t) {mi=t; ma=s;}
        else{ mi=s; ma=t;}
        int ss=n-ma;
        mi-=ss; //st
        int tt=n-(ss+mi);
        cout<<max(ss,tt)+1<<endl;
    }
  return 0;
}

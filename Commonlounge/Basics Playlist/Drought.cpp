#include <iostream>
using namespace std;
int main()
{
 int n,c,i,cnt=0,sum=0,k;
cin>>n>>c;
for(i=0;i<n;i++)
{
    cin>>k;
    cnt++;
     sum=sum+k;
     if(sum>=c){cout<<cnt;break;}
}
return 0;
}

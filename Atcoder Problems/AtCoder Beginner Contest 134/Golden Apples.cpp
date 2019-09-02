#include <iostream>

using namespace std;

int main()
{
   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   int n,d,c,temp=0,cnt=0;
   cin>>n>>d;

   while(1)
   {
       temp+=d*2+1;
       cnt++;
       if(temp>=n) break;
   }
   cout<<cnt<<endl;
    return 0;
}

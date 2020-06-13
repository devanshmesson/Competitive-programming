#include<bits/stdc++.h>
using namespace std;
main() 
{
   int x;
   cin>>x;
   int a[(2*x)+1];
   for(int i=0;i<(2*x);i++){cin>>a[i];}
   sort(a,a+(2*x));
   if(a[0]==a[(2*x)-1]){cout<<-1<<endl;return 0;}
   for(int  i=0;i<(2*x);i++)cout<<a[i]<<" ";
   return 0;
}

#include<iostream>
using namespace std;
 
int main()
{
int n,sum=0,s=0,t=0,g;
long long int b[1000];
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{
   cin>>a[i];
   if(i>0)
   {
   if(a[0]>=a[i]*2)
   {
       sum++;
       b[i]=i+1;
       t=t+a[i];
 
   }
 
   }
   s=s+a[i];
 
}
g=t+a[0];
 
if(a[0]>(s/2))
{
    cout<<"1"<<endl;
    cout<<"1";
    return 0;
}
else if(sum==0)
{
    cout<<"0"<<endl;
    return 0;
 
}
else if(g>(s/2))
{
cout<<sum+1<<endl;
cout<<"1"<<" ";
for(int i=1;i<n;i++)
{
    if(b[i]==0 || b[i]>100)
    {
        continue;
    }
cout<<b[i]<<" ";
}
}
else
{
    cout<<"0";
}
    return 0;
}

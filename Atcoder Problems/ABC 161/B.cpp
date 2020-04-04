#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int n,m,sum=0,cn=0,flag=0,cn1=0;
    cin>>n>>m;
    int a[n+1000];
    for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
    int w=4*m;
    float x=(float)sum/(float)w;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=x){cn++;}
    }
   if(cn<m)cout<<"No"<<endl;
   else cout<<"Yes"<<endl;
    return 0;
}

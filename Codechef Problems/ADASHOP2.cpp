#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,i=1,cnt=0;
        cin>>a>>b;
        int a1[]={1,2,3,4,5,6,7,8};
        int b1[]={0,1,2,3,3,2,1,0};
        c=a;d=b;
        if(a!=b)
        {
        cout<<27<<endl;
        a=(c+d)/2; b=(c+d)/2;
        cout<<a<<" "<<b<<endl;
        a=1;b=1;
        cout<<1<<" "<<1<<endl;
         a=2;b=2;
         cout<<2<<" "<<2<<endl;
        }
        else if(a==b && a!=1 && b!=1)
        {
            cout<<26<<endl;
            cout<<1<<" "<<1<<endl;
            a=2;b=2;
            cout<<2<<" "<<2<<endl;
        }
        else if(a==1 && b==1)
        {
         cout<<25<<endl;
         a=2;b=2;
         cout<<2<<" "<<2<<endl;
        }

        while(1)
        {
            if(a==a1[i])
            {
                a-=b1[i];b+=b1[i];
            }
                cout<<a<<" "<<b<<endl;
                swap(a,b);
                cout<<a<<" "<<b<<endl;
                a-=b1[i];b+=b1[i];
                cout<<a<<" "<<b<<endl;
                a++;b++;
                 cout<<a<<" "<<b<<endl;
            i++;
            if(i==7)break;
        }
    }
}

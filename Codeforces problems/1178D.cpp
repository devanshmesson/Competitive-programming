#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
bool isprime(int n)
{
    int flag=1;
    if(n==2 || n==3)return 1;
    else if(n%2==0 || n%3==0)return 0;
    for(int i=5;i*i<=n;i+=6)
    {
        if(n%i==0 || n%(i+2)==0){flag=0;break;}
    }
    return flag;
}
int main()
{
    int n;
    cin>>n;
    if(n<3)cout<<-1<<endl;
    if(isprime(n))
    {
        cout<<n<<endl;
        for(int i=1;i<n;i++)
        {
            cout<<i<<" "<<i+1<<endl;
        }
        cout<<n<<" "<<1<<endl;
    }
    else
    {
        int in;
        for(int i=n;i<=(3*n)/2;i++)
        {
            if(isprime(i)){in=i;break;}
        }
        int no=n+(abs(n-in));
        cout<<no<<endl;
        for(int i=1;i<n;i++)
        {
            cout<<i<<" "<<i+1<<endl;
        }
        cout<<n<<" "<<1<<endl;
        int i=1;
        while(i+in/2<=n && n+i<=no)
        {
            cout<<i<<" "<<i+(in/2)<<endl;
            i++;

        }

    }

}

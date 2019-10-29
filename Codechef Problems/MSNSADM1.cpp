#include <iostream>

using namespace std;

int main()
{
    long long int t,a[1000],b[1000],p;
    cin>>t;
    while(t--)
    {
        long long int n,maxm=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            a[i]=a[i]*20;
        }
        for(int i=0;i<n;i++)
        {

            cin>>b[i];
            b[i]=b[i]*10;
        }
        for(int i=0;i<n;i++)
        {
            p=a[i]-b[i];
            if(p>maxm)
            {
             maxm=p;
            }
        }
        cout<<maxm<<endl;

    }
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    long long int n,t,a[100000],g,sum=0,maxm=0;

    cin>>t;
    while(t--)
    {
        sum=0;
        maxm=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        for(int j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
              sum=0;
              int p=a[j] * a[k];

                g=p;

                while(g!=0)
                {
                 sum = sum + g%10;
                 g= g/10;

                }

                if(sum>maxm)
                {
                    maxm=sum;
                }

            }
        }
        cout<<maxm<<endl;

    }
    return 0;
}

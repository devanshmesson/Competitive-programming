#include <iostream>
using namespace std;



int main()
{
    long long int ar[100000];
    long double d,mn,sm;
    long double r;
    int f;
    cin>>r;
    for(int b=0;b<r;b++)
    {
        cin>>d;
        sm=0;
        for(int p=0;p<d;p++)
        {
            cin>>ar[p];
            sm=sm+ar[p];
        }
        mn=sm/d;

        for(int u=0;u<d;u++)
        {
            f=0;
             if(ar[u]==mn)
            {
                cout<<u+1<<endl;
                f=1;
                
                break;
            }
        }
         if(f==0)
         {
             
             cout<<"Impossible"<<endl;
         }



    }

    return 0;
}

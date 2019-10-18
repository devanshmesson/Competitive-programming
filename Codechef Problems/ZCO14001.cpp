#include <iostream>

using namespace std;

int main()
{
    int n,h,t=-1,flag=0;
    cin>>n>>h;
    int a[n];


    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }
    int i=0;
    while(t!=0)
    {

        cin>>t;
        if(t==1)
       {
           if(i==0)
            {
                i=0;
            }
            else
            {
                i=i-1;
            }
       }
        else if(t==2)
        {
            if(i==(n-1))
            {
                i=n-1;
            }
            else
            {
                i=i+1;
            }
        }
        else if(t==3)
        {
            if(flag==0 && a[i]>0)
            {
             a[i]=a[i]-1;
             flag=1;
            }
        }

        else if(t==4)
        {
           if(flag==1 && a[i]<h)
           {
            a[i]=a[i]+1;
            flag=0;
           }
        }

    }
      for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }

    return 0;
}

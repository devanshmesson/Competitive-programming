#include <iostream>

using namespace std;

int main()
{
    int t,b,d,max=0,x=0,y=0,ar[10000],temp;
    int a;
    cin>>t;
    for(int i=0;i<t;i++)
    {

        cin>>a>>b;
        x=x+a;
        y=y+b;
        if(y>x)
        {
           d=y-x;
            if(d>max)
        {
            max=d;
            temp=2;
        }
        }
           else
           {
            d=x-y;
             temp=1;
             if(d>max)
        {
            max=d;
            temp=1;
        }
           }


    }
   cout<<temp;
   cout<<" ";
   cout<<max;



    return 0;
}

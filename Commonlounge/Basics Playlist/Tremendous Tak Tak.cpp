#include <iostream>
using namespace std;
int main()
{
    int tnof,count=0;
    cin>>tnof;
    while(1)
    {
        if((tnof-1)%11!=0)
        {
            tnof=tnof*2;
            count++;
        }
         else
         {
             break;
         }
    }
    cout<<count<<" "<<tnof;
}

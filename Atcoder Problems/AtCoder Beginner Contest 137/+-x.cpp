#include <iostream>

using namespace std;

int main()
{
    int a,b,add,mi,mul;
    cin>>a>>b;
    add=a+b;
    mi=a-b;
    mul=a*b;
    if(add>mi)
    {
        if(add>mul)
        {
            cout<<add<<endl;
            return 0;
        }
    }
    else
    {
         if(mi>mul)
        {
            cout<<mi<<endl;
            return 0;
        }
    }
    cout<<mul<<endl;

    return 0;
}

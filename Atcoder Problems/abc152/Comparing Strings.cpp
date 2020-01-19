#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    if(a>b)
    {
        for(int i=0;i<a;i++)cout<<b;
    }
    else for(int i=0;i<b;i++)cout<<a;
    return 0;
}

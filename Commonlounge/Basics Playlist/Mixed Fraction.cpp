#include <iostream>
using namespace std;
int main()
{
    int n,d,a,b;
    cin>>n>>d;
    a=n/d;
    b=n%d;
    if(d!=0) cout<<a<<" "<<b<<"/"<<d;
    else cout<<a;

    return 0;
}

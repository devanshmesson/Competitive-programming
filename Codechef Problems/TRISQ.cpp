#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,b;
        cin>>n;
        if(n%2!=0)n--;
        b=n/4;
        cout<<((n*n)/8)-b<<endl;

    }
    return 0;
}

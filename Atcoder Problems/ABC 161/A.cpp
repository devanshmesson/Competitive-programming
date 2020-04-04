#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int a,b,c;
    cin>>a>>b>>c;
    swap(a,b);
    swap(a,c);
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}

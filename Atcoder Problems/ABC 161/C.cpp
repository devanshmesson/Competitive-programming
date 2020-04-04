#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int n,k;
    cin>>n>>k;
    int s=n/k;
    n=n-(s*k);
    while(1)
    {
        if(n>abs(n-k))n=abs(n-k);
        else break;
    }
    cout<<n<<endl;
    return 0;
}

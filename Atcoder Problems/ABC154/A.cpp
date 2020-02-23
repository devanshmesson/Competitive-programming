#include <iostream>

using namespace std;

int main()
{
    string s,t,u;
    int a,b;
    cin>>s>>t;
    cin>>a>>b;
    cin>>u;
    if(s==u)cout<<a-1<<" "<<b<<endl;
    else if(u==t) cout<<a<<" "<<b-1<<endl;
    else if(s==u && s==t)cout<<a-1<<" "<<b-1<<endl;

    return 0;
}

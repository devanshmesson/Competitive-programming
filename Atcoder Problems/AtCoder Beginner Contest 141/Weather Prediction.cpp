#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    while(1)
    {
        if(s=="Sunny") {cout<<"Cloudy"; break;}
        else if(s=="Cloudy") {cout<<"Rainy"<<endl; break;}
        else if(s=="Rainy") {cout<<"Sunny"<<endl; break;}
    }
    return 0;
}

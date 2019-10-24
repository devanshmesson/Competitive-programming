#include <iostream>

using namespace std;

int main()
{
    int t,x,y,k;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>x;
        cin>>y;
        cin>>k;

       int d=(x+y)/k;

       if(d%2==0)
       {
           cout<<"Chef"<<endl;
       }
       else
       {
           cout<<"Paja"<<endl;
       }


    }
    return 0;
}

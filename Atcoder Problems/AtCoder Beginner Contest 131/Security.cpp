#include <iostream>
#include<string.h>

using namespace std;

int main()
{
    char S[4];
    cin>>S;
    int flag=0;
    for(int i=0;i<strlen(S);i++)
    {
        if('0'<S[i]<'9')
        {


        if(S[i]==S[i+1])
        {
            flag=1;
        }
        }

    }
    if(flag==0)
    {
        cout<<"Good";
    }
    if(flag==1)
    {
        cout<<"Bad";
    }


    return 0;
}

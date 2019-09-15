#include <iostream>

using namespace std;

int main()
{
    string s;
    int i=0,flag=1;
    cin>>s;
    while(s[i]!='\0')
    {
        if(i%2==0)
        {
            if(s[i]=='R' ||s[i]=='U'||s[i]=='D')
            {
                flag=1;
            }
            else {flag=0;cout<<"No"<<endl;break;}
            i++;
        }
        else if(i%2!=0)
        {
         if(s[i]=='L' ||s[i]=='U'||s[i]=='D')
            {
                flag=1;
            }
            else {flag=0;cout<<"No"<<endl;break;}
            i++;
        }
    }
    if(flag==1)cout<<"Yes"<<endl;
    return 0;
}

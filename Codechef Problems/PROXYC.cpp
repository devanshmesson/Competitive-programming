#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        float att,d,p=0,pxy=0,sum=0;

        cin>>d;
        string s;
        cin>>s;

        for(int i=0;i<d;i++)
        {
            if(s[i]=='P')
            {
                p++;
            }
        }
     //   cout<<"present="<<p<<endl;
        for(int i=0;i<d;i++)
        {
             sum=pxy+p;
            // cout<<"sum="<<sum<<endl;
            att=sum/d;
           // cout<<"att="<<att<<endl;

            if(att>=0.75)
            {
                cout<<pxy<<endl;
                break;
            }

            if(i>1 && i<d-2)
            {
            if(s[i]=='A')
            {
                if((s[i-1]=='P' ||s[i-2]=='P') &&(s[i+1]=='P'||s[i+2]=='P'))
                {
                    pxy++;
                }
            }
            }
            //cout<<"pxy="<<pxy<<endl;

        }
        if(att<0.75||att==0)
            {
                cout<<"-1"<<endl;
            }
    }


    return 0;
}

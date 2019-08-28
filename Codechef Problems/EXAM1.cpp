#include <iostream>

using namespace std;

int main()
{
    int t,flag=0;
    cin>>t;
    for(int v=0;v<t;v++)
    {
        int n,cnt=0;
        cin>>n;
        char s[n];
        cin>>s;
        char u[n];
        cin>>u;

        for(int i=0;i<n;)
        {
            if('A'<=s[i]<='D')
            {
              if('A'<=u[i]<='D' || u[i]=='N')

            {
            if(s[i]==u[i])
             {
                flag=1;
                cnt++;
                i++;
             }

            else if(u[i]=='N')
             {
                 i++;
             }
             else if(u[i]!=s[i])
             {
               i=i+2;

             }
            }
        }
        }

        if(flag==1)
        {
            cout<<cnt<<endl;
        }

}
return 0;
}

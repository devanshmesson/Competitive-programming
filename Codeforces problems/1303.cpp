#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t_kkk;
    cin>>t_kkk;
    for(int h=0;h<t_kkk;h++)
    {
        int hello=0;
        string a;
        cin>>a;
         int  devansh=0;

        for(int i=0;i<a.size();i++)
        {
            if(a[i]=='1')
            {
                int f=i+1;
                devansh=1;
                int mess=0;
                while(a[f]=='0' && f<a.size())
                {
                    if(a[f]=='0'){hello++;mess++;}
                    if(a[f]=='1'){devansh=0;break;}
                    if(f==a.size()-1 && a[f]!='1')hello-=mess;
                    f++;
                }

            }
        }
        cout<<hello<<endl;
    }
    return 0;
}

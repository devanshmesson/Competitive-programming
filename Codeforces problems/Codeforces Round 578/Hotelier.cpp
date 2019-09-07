#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,i=0,a=0,j=0,t,k=9;
    vector<long long int> v;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<10;i++)
    {
        a=0;
        v.push_back(a);
    }
    while(s[i]!='\0' && j<10 && k<10)
    {
        if(s[i]=='L')
        {
            for(int j=0;j<10;j++)
            {
                if(v[j]==0){v[j]=1; break;}
            }
          i++;
        }
        else if (s[i]=='R')
        {
            for(int k=9;k>=0;k--)
            {
                if(v[k]==0){v[k]=1; break;}
            }
            i++;
        }
        else if(s[i]>='0'&& s[i]<='9')
        {
            t=s[i]-'0';
            v[t]=0;
            i++;
        }

    }
        for(int i=0;i<10;i++)
         {
            cout<<v[i];
         }

    return 0;
}

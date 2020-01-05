#include <iostream>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int t;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        int n,i=0,cnt=0;
        string s;
        cin>>n;
        cin>>s;
 
        while(1)
        {
int f=1;
int i=0;
        while(s[i]!='\0')
        {
          if(s[i]=='A' && s[i+1]=='P'){s[i+1]='A';f=0;i+=2;}
          else i++;
 
        }
        if(f==0)cnt++;
         int k=0,flag=1;
            while(s[k]!='\0')
            {
              if(s[k]=='A' && s[k+1]=='P'){flag=0;break;}
            k++;
            }
            if(flag==1)break;
        }
                cout<<cnt<<endl;
 
    }
 
    return 0;
}

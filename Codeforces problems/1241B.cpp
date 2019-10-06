#include <iostream>

using namespace std;

int main()
{
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
       string t;
       string s;
       cin>>s;
       cin>>t;
      int flag=1;
       //sort(s.begin(),s.end());
       //sort(t.begin(),t.end());

         for(int i=0;i<s.size();i++)
         {
             for(int j=0;j<t.size();j++)
             {
                 if(s[i]==t[j]){flag=0;cout<<"YES"<<endl;break;}
             }
             if(flag==0)break;
         }

          if(flag==1)cout<<"NO"<<endl;

    }


    return 0;
}

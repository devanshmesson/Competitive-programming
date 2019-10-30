#include <iostream>

using namespace std;

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       long long int n,k,y;
       cin>>n>>k;
       y=n/k;
       for(int i=0;i<k;i++)
       {
           if(y%k==0 || k==1 )
           {
               cout<<"NO"<<endl;
               break;

           }
           else
           {
               cout<<"YES"<<endl;
               break;
           }

       }


   }
    return 0;
}

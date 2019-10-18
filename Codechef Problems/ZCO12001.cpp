#include <iostream>

using namespace std;

int main()
{
    int n,p,cnt=0,maxm=0,pos=0,max_sym=0,pos_sym=0,max_final=0,pos_final=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p;
        if(cnt==0)
        {
            max_sym=0;
            pos_sym=i+1;
        }
         if(cnt>maxm)
        {
            maxm=cnt;
            pos=i;
        }
        if(p==1)
        {
            cnt++;
        }
        if(p==2)
        {
            cnt--;
            max_sym+=2;
        }


        if(max_sym>max_final)
        {
            max_final=max_sym;
            pos_final=pos_sym;
        }

    }
    cout<<maxm<<" "<<pos<<" "<<max_final<<" "<<pos_final;
    return 0;
}

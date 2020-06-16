#include <iostream>
using namespace std;
int main()
{
    int a,b,cnt=0,j=0;
    int arr[50001],ar[50001];
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<a;i++)
    {
        if(arr[i]%3==0)
        {
            cnt++;
            ar[j]=++i;
            j++;
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
    {
        cout<<ar[i]<<" " ;
    }

    return 0;
}

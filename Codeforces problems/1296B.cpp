#include <bits/stdc++.h>
using namespace std;
#define int long long int
int con(int num)
{
    // Base case for recursion termination
    if (num == 0)
        return 0;

    // Extraxt the last digit and
    // change it if needed
    int digit = num % 10;
    if (digit == 0)
        digit = 1;

    // Convert remaining digits and
    // append the last digit
    return con(num/10) *10 + digit;
}
int fd(int n)
{
    // Find total number of digits - 1
    int digits = (int)log10(n);

    // Find first digit
    n = (int)(n / pow(10, digits));

    // Return first digit
    return n;
}
int cnt(int n)
{
    if (n == 0)
        return 0;
    return 1 + cnt(n / 10);
}

int f(int n)
{
    int num=1;
    for(int i=0;i<n-1;i++)
    {
      num*=10;
    }
    return num;
}

main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //#define int long long int
    int t;
    cin>>t;
    while(t--)
    {
        int n,sum=0,tm,y,r;
        cin>>n;
        if(cnt(n)==1){cout<<n<<endl;continue;}
        if(n==f(cnt(n)))
        {
          cout<<con(n)<<endl;
          continue;
        }

        while(1)
        {
            tm=f(cnt(n));
            y=tm*fd(n);
            r=y/10;
            sum+=tm*fd(n);
            //cout<<"sum="<<sum<<endl;
            n-=y;
            n+=r;
            //cout<<"n="<<n<<endl;
            if(cnt(n)==1){sum+=n;break;}
            //cout<<sum<<endl;
        }
        cout<<sum<<endl;


    }

}

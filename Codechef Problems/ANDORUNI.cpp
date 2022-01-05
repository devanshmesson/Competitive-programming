#include<bits/stdc++.h>
using namespace std;
#define int long long int
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    scanf("%lld",&n);
    int a[n+1];
    int b[n+1];
    int ii=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]>0)
         {
             b[ii]=a[i];
             ii++;
         }
    }
    int ans=0;
 for (int i = 0; i < 32; i++)
    {
        int k = 0;  
        for (int j = 0; j < ii; j++)
            if ( (b[j] & (1 << i)) )
                k++;
        if(k>=2)ans |= (1<<i) ;
    }
   printf("%lld\n",ans);
  }    
}

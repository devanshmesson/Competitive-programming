#include <stdio.h>
#include<math.h>
#define ll long long int
double ilog(double base, double x)
{
    return (double)(log(x) / log(base));
}
inline ll f(ll i) {
    i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}
int main()
{
   int t;
 scanf("%d",&t);
   while(t--)
   {
       int n,q,a;
      scanf("%d",&n);
      scanf("%d",&q);
       int e=0,o=0;
       for(int i=0;i<n;i++)
       {
          scanf("%d",&a);
          if(ilog(2,a)==(int)ilog(2,a)){o++;continue;}
          if(f(a)%2==0)e++;
          else o++;
       }
       for(int i=0;i<q;i++)
       {
            scanf("%d",&a);
           if(ilog(2,a)==(int)ilog(2,a)){printf("%d ",o);printf("%d",e);printf("\n");continue;}
           if(f(a)%2!=0){printf("%d ",o);printf("%d",e);printf("\n");}
           else {printf("%d ",e);printf("%d",o);printf("\n");}
       }


   }
    return 0;
}

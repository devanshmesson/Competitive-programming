#include<bits/stdc++.h>
using namespace std;
int countZeros(int x) 
{ 
    unsigned y; 
    int n = 32; 
    y = x >> 16; 
    if (y != 0) { 
        n = n - 16; 
        x = y; 
    } 
    y = x >> 8; 
    if (y != 0) { 
        n = n - 8; 
        x = y; 
    } 
    y = x >> 4; 
    if (y != 0) { 
        n = n - 4; 
        x = y; 
    } 
    y = x >> 2; 
    if (y != 0) { 
        n = n - 2; 
        x = y; 
    } 
    y = x >> 1; 
    if (y != 0) 
        return n - 2; 
    return n - x; 
} 


main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
     for(int j=i+1;j<n;j++)
      {
        string s=" ";
       for (int q = 31; q >= 0; q--) 
       { 
        int k = a[i]>> q; 
        if (k & 1)s+='1';
        else s+='0';
       }  
      
       int st=countZeros(a[i]);
       s=s.substr(st+1,32-st+1);
       string d=" ";
       for (int q = 31; q >= 0; q--) 
       { 
        int k = a[j] >> q; 
        if (k & 1)d+='1';
        else d+='0';
       }  
       st=countZeros(a[j]);
       d=d.substr(st+1,32-st+1);
       string xy=s+d;
       string yx=d+s;
      int dec_value = 0; 
      int base = 1; 
      int len = xy.length(); 
      for (int i = len - 1; i >= 0; i--) 
      { 
        if (xy[i] == '1') dec_value += base; 
        base = base * 2; 
      } 
     int numxy=dec_value;

     dec_value = 0; 
      base = 1; 
      len = yx.length(); 
      for (int i = len - 1; i >= 0; i--) 
      { 
        if (yx[i] == '1') dec_value += base; 
        base = base * 2; 
      } 
     int numyx=dec_value;
    ans=max(ans,abs(numxy-numyx));
      }
    } 
    cout<<ans<<endl;
  }
}

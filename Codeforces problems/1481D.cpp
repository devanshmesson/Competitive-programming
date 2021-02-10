#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

char graph[1001][1001];
int permute[3],flag;

int* permutation(int l,int r,int *ans)
{
  if(l==r && graph[permute[0]][permute[1]]==graph[permute[1]][permute[2]])
  {
    for(int i=0;i<=2;i++)ans[i]=permute[i];
    flag=0;
  }
  for(int i=l;i<=r;i++)
  {
    swap(permute[i],permute[l]);
    if(flag==1)permutation(l+1,r,ans);
    swap(permute[i],permute[l]);
  }
  return ans;
}

main() 
{
  int t;
  cin>>t;
  for(int i=0;i<=2;i++)permute[i]=i+1;
  while(t--)
  {
    int *ans=(int*)malloc(3*sizeof(int));
    flag=1;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        cin>>graph[i][j];
      }
    }

    int found=0,ii=1,jj=2;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        if(i!=j && graph[i][j]==graph[j][i])
        {
          found=1;
          ii=i;jj=j;
          break;
        }
      }
      if(found==1)break;
    }

    if(found==1 || m%2==1)
    {
        cout<<"YES"<<endl;
        for(int k=1;k<=m+1;k++)
        {
          if(k%2==0)cout<<ii<<" ";
          else cout<<jj<<" ";
        }
        cout<<endl;
        continue;
    }

    if(n<3){cout<<"NO"<<endl;continue;}
    int *ans1=permutation(0,2,ans);

    int x=ans1[0],y=ans1[1],z=ans1[2];

    if((m/2)%2==1)
    {
       //aabbaa ->xyzyx...
       cout<<"YES"<<endl;
       for(int i=0;i<m+1;i++)
       {
         if(i%4==0)cout<<x<<" ";
         else if(i%4==1)cout<<y<<" ";
         else if(i%4==2)cout<<z<<" ";
         else if(i%4==3)cout<<y<<" ";
       }
       cout<<endl;
       continue;
    }

    if((m/2)%2==0)
    {
      //abba abba ->yzyxy...
      cout<<"YES"<<endl;
      for(int i=0;i<m+1;i++)
      {
         if(i%4==0)cout<<y<<" ";
         else if(i%4==1)cout<<z<<" ";
         else if(i%4==2)cout<<y<<" ";
         else if(i%4==3)cout<<x<<" ";
      }
      cout<<endl;
      continue;
    }
    cout<<"NO"<<endl;
  }
}

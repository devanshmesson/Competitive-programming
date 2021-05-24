#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int sz=3000;
int mat[sz][sz],prerow[sz][sz],precol[sz][sz];
main()
{

    int var=0;
	for(int i=1;i<2000;i++)
	{
	  int st=i;
	  int x=1,y=i;
	  while(st>0)
	  {
	  	var++;
	  	mat[x][y]=var;
	  	x++;
	  	y--;
	  	st--;
	  }
	}
    
    memset(prerow,0,sizeof(prerow));
    memset(precol,0,sizeof(precol));

 	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=1000;j++)
		{
			prerow[i][j]=mat[i][j] + prerow[i][j-1];
			precol[j][i]=mat[j][i] + precol[j-1][i];
		}
	}

	int t;
	cin>>t;

	while(t--)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
        int down=precol[x2][y1]-precol[x1-1][y1];
        int right=prerow[x2][y2]-prerow[x2][y1];
        cout<<down+right<<endl;

	}

}

    

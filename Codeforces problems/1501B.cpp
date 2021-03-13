#include<bits/stdc++.h>
using namespace std;

vector<int> initializeDiffArray(vector<int>& A) 
{ 
    int n = A.size(); 

    vector<int> D(n + 1); 
  
    D[0] = A[0], D[n] = 0; 
    for (int i = 1; i < n; i++) 
        D[i] = A[i] - A[i - 1]; 
    return D; 
} 
  
void update(vector<int>& D, int l, int r, int x) 
{ 
    D[l] += x; 
    D[r + 1] -= x; 
} 
int printArray(vector<int>& A, vector<int>& D) 
{ 
    for (int i = 0; i < A.size(); i++) { 
        if (i == 0) 
            A[i] = D[i]; 
  
        // Note that A[0] or D[0] decides 
        // values of rest of the elements. 
        else
            A[i] = D[i] + A[i - 1]; 
  
            if(A[i]>=1)cout << 1 << " ";
            else cout<<0<<" "; 
          
    } 
    cout << endl; 
} 
main()
{
 ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 int t;
 cin>>t;
 while(t--)
 {
  int n;
  cin>>n;
  vector<int>a(n+1),ans(n);
  int m;
  for(int i=1;i<=n;i++){cin>>a[i];ans[i-1]=0;}
  vector<int> D = initializeDiffArray(ans); 
  for(int i=n;i>=1;i--)
  {
    if(a[i]==0){continue;}
    int till = max(i-a[i]+1,1);
    update(D, till-1, i-1, 1); 
  }
  printArray(ans, D);
  cout<<endl;
 }
} 

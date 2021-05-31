#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define freopen freopen("input.txt","r",stdin);freopen("output1.txt","w",stdout);
#define endl "\n"

const int MAX = 10000000;
 
// prefix[i] is going to store count of primes
// till i (including i).
int prefix[MAX + 1];
bool prime[MAX + 1];

void buildPrefix()
{
    // Create a boolean array "prime[0..n]". A
    // value in prime[i] will finally be false
    // if i is Not a prime, else true.
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= MAX; p++) {
 
        // If prime[p] is not changed, then
        // it is a prime
        if (prime[p] == true) {
 
            // Update all multiples of p
            for (int i = p * 2; i <= MAX; i += p)
                prime[i] = false;
        }
    }
 
    // Build prefix array
    prefix[0] = prefix[1] = 0;
    for (int p = 2; p <= MAX; p++) {
        prefix[p] = prefix[p - 1];
        if (prime[p])
            prefix[p]++;
    }
}
 
// Returns count of primes in range from L to
// R (both inclusive).
int help(int L, int R)
{
    return prefix[R] - prefix[L - 1];
}
 
 
main()
{
  int t;
  cin>>t;
  buildPrefix();
  while(t--)
  {
    int n;
    cin>>n;

    int num=n/2;
    num++;
    int prim=help(num,n);
    
    int c=0;
    if(2>=num && 2<=n)c=1;

    cout<<prim+1-c<<endl;
    // cout<<prim+1<<endl;
  }
}

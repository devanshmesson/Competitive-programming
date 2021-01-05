#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define endl "\n"
#define int long long int

int log(int a,int b) 
{ 
    return (a > b - 1) ? 1 + log(a / b, b) : 0; 
} 

int power(int x, unsigned int y) 
{ 
    int res = 1;    
    while (y > 0) 
    { 
        if (y & 1) res = res*x; 
        y = y>>1; 
        x = x*x; 
    } 
    return res; 
}
main()
{
    freopen
    io
    int t;
    cin>>t;
    while(t--)
    {
      int n,x;
      cin>>n>>x;
      /*
       I visualised this problem in a matrix form:
       for example:

       Input :
       1 
       4 2
       4 6 8 2

       Matrix (mat)-

       1 copies: 4 6 8 2 
       2 copies: 2 3 4 1
       4 copies: 1 s s s   (here 's' means  stop creating copies)

       mat[i][j] = x copies of (mat[i-1][j] / x) 

       Iterate the matrix from left to right row-wise and
       stop creating copies if a number is found which is not divisible
       by x.

       In the example, i stopped creating copies when 3 was found
       ,that's why i wrote 's' on it.
      */

      int ref=log(10000000000,x); //Calculating the power which will be raised to x.
      ref++; //increasing by 1 for safe side.
      ref=power(x,ref);  // a big number (greater than input) for calulating GCD.
  
      int a[n+1];
      int gcd,level,minlev=10000,levindex;
    
      /*
      Approach -
      i precomputed the number from which i need to stop creating copies.

      Calculate how long the number is divisible by x.
      In other words (visualize matrix) , calculate number of rows
      for a particular column from which you have to stop creating copies.

      For understanding the above statement see the matrix:
      For first column (element 4),after 2 rows , you have to stop creating 
      copies for element 4.

      [1]Do this for all elements and choose the first element(column)
      with smallest number of rows from which you have to stop creating copies.

      Here level means number of rows for a column after which you have to stop creating copies.

      Why to do [1] ? 

      See the matrix above:

      [Iteration 1] For element 4 : Level = 2 , Minimum level = 2 , column with Minimum level = 1
      [Iteration 2] For element 6 : Level = 1 , Minimum level = 1 , column with Minimum level = 2
      [Iteration 3] For element 8 : Level = 3 , Minimum level = 1 , column with Minimum level = 2
      [Iteration 4] For element 2 : Level = 1 , Minimum level = 1 , column with Minimum level = 2

      When you will iterate from right to left , row-wise , the element from where 
      you will stop creating copies will be the first element(column)
      with smallest number of rows from which you have to stop creating copies.

      Hence proved [1] !
      */

      /*
       How to calculate the level for each column.

       Here level means number of rows for a column after which you have to stop creating copies.
       
       1.Calculate greatest common divisor between the element and a big number(of the form x^20)

       Explaination for 1 
       {
       why x^20 or something?
      -its an exponent to x (must be greater than element) because the required number (largest number which can divide the element)
       is also an exponent to x.

       We are continously dividing the element by x.
       we have to find the largest number which can divide the element.

       lets say element = 4 and x = 2
       4 (1 copy)-> 2 (2 copies)-> 1 (4 copies)
       thus,4 can be divide to 4 copies of 1.
       }

       2.Till now we have found the largest no. of copies an element
         will make.

         [2]To calculate till which level its making the largest
         no. of copies you have to calculate log of (largest no. of copies) 
         to the base x.

         why [2] is true?
         -The element is being divided by x continuously and 
         number of copies are increasing by an exponent of x.

         Example of above statement -
         element = 4 , x=2 

         4 (1 copy)-> 2 (2 copies)-> 1 (4 copies)
      -> 4 (2^0 copy)-> 2 (2^1 copies)-> 1 (2^2 copies).

         we have to calculate till which level , 2^2 copies are made.

         log(2^2) to the base 2 , this will tell the level till which 
         2^2 copies are made.

         So, to generalise it , 
         Formula for calculating number of rows for a column from which you 
         will stop creating copies will be: log(gcd(element,x^20)) to the base x.
      */

      for(int i=0;i<n;i++)
      {  
        cin>>a[i];
        gcd=__gcd(a[i],ref); //largest no. copies a[i] will make and after which it cannot be further divide by x.
        level=log(gcd,x);  //Calculating the level (no. of rows) till which largest number of copies are made.
        if(level<minlev) //choosing the first element(column) with smallest number of rows from which you have to stop creating copies.
        {
          minlev=level;  //storing the level.
          levindex=i; //storing the column.
        }
      }
      int sum=0,cnt;
      int copies=1;

     for(int i=0;i<n;i++)sum+=a[i]; //This will be obvious for every case

      /*
       This loop is creating all copies of elements till the element()
       is found from which making copies are stopped. 

       *Lets call the element from which making copies are stopped as "benchmark" *
      */

      for(int i=0;i<n;i++)
      {
          if(i>=levindex)cnt=minlev; //copies cannot be made after the benchmark is reached so copies can be made till minlev.
          else if(i<levindex)cnt=minlev+1;//+1 because copies of elements can be made which are before the benchmark.
          int element=a[i];
          copies=1;
          while(cnt)
          {
            element/=x; //dividing the element continuously by x
            copies*=x;  //multiplying with no. of copies of that element 
            sum+=element*copies; //summing those copies 
            cnt--; 
          }
      }
      cout<<sum<<endl;
    }
  }

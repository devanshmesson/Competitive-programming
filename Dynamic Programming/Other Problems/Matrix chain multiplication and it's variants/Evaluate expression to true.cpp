/*
Problem - Given a string consisting of characters :
F (false)
T (true)
| (bitwise OR)
^ (bitwise XOR)
& (bitwise AND)

Find number of ways to evaluate the expression in such a way that the answer is TRUE
Evaluating the expression (string) means Partitioning the string and then solving it.

Link - https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

For example:
String -  T^F|T

1st way : (T) ^ (F | T)       [Partitioned on index 1 (1-based indexing)]
        : (T) ^ (T)
        : False

2nd way : (T ^ F) | (T)       [Partitioned on index 3 (1-based indexing)]
        : (T) | (T)
        : True
        
Answer is 1. because there is only 1 way to evaluate the expression to TRUE.

Matrix chain multiplication is the parent question of this problem because it is clearly visible that we have to partition the string and calculate the answer.

Observations : 
1. Property of XOR : True ^ False = TRUE  
                   : False ^ True = TRUE   (REFERENCE : 1)
                   : True ^ True =  False 
                   : False ^ False = False 

2. Property of OR : True | False = TRUE  
                   : False | True = TRUE  
                   : TRUE | TRUE = TRUE
                   : False | False = False
 
3. Property of AND : True & False = FALSE 
                   : False & True = FALSE 
                   : TRUE & TRUE = TRUE
                   : False & False = False
                  
                  

False is also an operand to evaluate the expression as True (refer (1)).So this means that after partitioning the string into two,
we have to evaluate the left part and the right part of the string as False as well as True. 

Suppose left part of the array can be evaluated False in 2 different Ways. (Let it be a)
Suppose left part of the array can be evaluated True in 3 different Ways.  (Let it be b)
Suppose Right part of the array can be evaluated False in 4 different Ways.(Let it be c)
Suppose Right part of the array can be evaluated True in 1  way.           (Let it be d)

If the operator is | (Bitwise OR) between the left and right part, then if number of ways in which answer can come True is:

(a*d) + (b*d) +(b*c) => (2*1) + (3*1) + (3*4) => 17 ways

So, in 17 ways this expression in a particular partition can be evaluated as True.

So partition the expression at every index (leaving the operators) and calculate number of ways like discussed above.Finally, sum all the ways at the end.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int,int> dp[201][201];
    pair<int,int> operate(char x,int ltrue,int lfalse,int rtrue,int rfalse)
    {
  
    int tru=0,fal=0;
    if(x=='&')
    {
       (tru=ltrue * rtrue);
        (fal=(ltrue*rfalse) + (lfalse*rtrue) + (lfalse*rfalse));
    }
    if(x=='|')
    {
        fal=(lfalse * rfalse);
        tru=((ltrue*rfalse) + (lfalse*rtrue) + (ltrue*rtrue));
    }
    if(x=='^')
    {
        tru=((ltrue * rfalse) + (lfalse*rtrue));
        fal=((ltrue*rtrue) + (lfalse*rfalse));
    }
    return {tru,fal};
    }
pair<int,int> MCM(string &A,int i,int j)
{
    //Step 2: Base condition : first invlaid input
    if(i==j){if(A[i]=='T')return {1,0};else return {0,1};}
    if(i>j)return {0,0};
    
    if(dp[i][j].first!=-1 && dp[i][j].second!=-1)return dp[i][j];
    
    int cnt=0,falseans=0,trueans=0;
    //Step 3: Write for loop, according to problem
    for(int k=i;k<=j-2;k+=2)
    {
        int lfalse=0,ltrue=0,rfalse=0,rtrue=0;
        pair<int,int>pa;
        
        pa=MCM(A,i,k);       //Calculating number of ways for left part of the expression
        ltrue=pa.first;      //Storing number of ways in which answer is TRUE
        lfalse=pa.second;     //Storing number of ways in which answer is FALSE
    
        pa=MCM(A,k+2,j);     //Calculating number of ways for right part of the expression
        rtrue=pa.first;      //Storing number of ways in which answer is TRUE
        rfalse=pa.second;     //Storing number of ways in which answer is FALSE
                 
        pa=operate(A[k+1],ltrue,lfalse,rtrue,rfalse);    // Calculating the number of ways for this whole expression. LEFT (some operator) RIGHT
        
        (falseans += pa.second);   //Summing all the ways of each partition because we have to find all the ways.
        (trueans += pa.first);
    }
    return dp[i][j]={trueans%1003,falseans%1003};
}
    int countWays(int N, string S)
    {
       
    //Step:1 Select i and j
    memset(dp,-1,sizeof(dp));
    return MCM(S,0,N-1).first;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends

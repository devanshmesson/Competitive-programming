/*
Problem link - https://leetcode.com/problems/powx-n/submissions/
Solution:1 Multiply x by itself n times.
Time complexity - O(n)

Solution:2 Apply binary exponentiation
Time complexity-O(Log n)
*/
class Solution {
public:
    double myPow(double x, int n) 
    {
        long long int n1=n;
        bool isnegative=false;
        if(n1<0)isnegative=true;
        n1=abs(n1);
        double ans=1;
        
        while(n1>=1)
        {
            if(n1%2==0)
            {
                n1/=2;
                x=x*x;
            }
            else
            {
                n1--;
                ans*=x;
            }
        }
     // if()cout<<ans<<endl;
     if(isnegative==true)ans=1/ans;
     return ans;
        
        
    }
};

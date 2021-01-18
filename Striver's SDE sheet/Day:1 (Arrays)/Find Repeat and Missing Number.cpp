/*
Problem Link - https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Solution - Using XOR

Problem in my words - There are 'n' numbers in the array
                    - Out of those n numbers , one number is repeted 2 times and one number is missing.
                    - Find the dupicate number and missing number
                    
 How it got striked in mind that XOR should be used?  
 ANS - due to XOR property which is :  x ^ x = 0                     -----  let this be (1) 
                                    :  x ^ x ^ x = x                 -----  let this be (2) 
                                    :  x = x (not XORED with anyone) -----  let this be (3) 
                                    :  If the XOR result ( of lets say (x and y) ) has ith bit set , it means either x has ith bit set or y has ith bit set.  ----  let this be (4) 
                                   
 Observation 1. Out of these n numbers , n-2 numbers appear exactly once.
             2. If the given array is XORED with the range of [1 to n] , These n-2 numbers discussed above will be ommitted (refer (1) ).
                2.1 Lets take an example to understand what i said above -
                2.2 Let the array be [4 3 6 2 1 1] , range is [1 to 6]
                2.3 Out of 6 numbers , 4 numbers which are - 2,3,4,6 will be ommitted if this array is XORED with the range[1 to 6] (refer (1) ).
                2.4 Illustration - (1^2^3^4^5^6) ^ (4^3^6^2^1^1)
                                 2.4.1 Remaining value after XOR: (1^5) ^ (1^1)
                
             3. After those n-2 numbers are ommitted , then remaining 2 numbers (repeted) will result into one of those 2 numbers (refer (2)).
                3.1 Lets continue the previous example to understand what i said above
                3.2 (1^5) ^ (1^1)
                3.3 (5) ^ (1^1^1)
                3.4 (5) ^ (1)
                3.5 In the above example repeted number was 1 which was appeared two times.When these two 1's got XORED with the 1 of the range[1 to 6],
                     result was 1.In other words,(1^1^1)=1
                    
             4. So Conclusion from point 3 is that the duplicate number is still remaining in the result.
             
             5.Moving back to the remaining XOR value of the example , there is a number 5 in the result.
               5.1 This number 5 is not being XORED with anyone so it is still 5. (Refer (3)
               5.2 Why is it not XORED with anyone? because 5 was missing in the given array [4 3 6 2 1 1].
               5.3 This 5 belongs to the range[1 to 6].Since 5 was missing in the given array,it remained as it is in the result.
               
             6. So Conclusion from point 5 is that the missing number is also present in the result along with the duplicate number.
             
             7. These two are the numbers which we needed finally.But In coding , these numbers will be XORED and they will be in the form of a single number.
                7.1 The above statement means to say that the result - 5 ^ 1 will be computed and saved as the 4 (5^1=4).
             
             8.We need to find out the missing number and the duplicate number from 4.Thats our task.
             
             
             
             
               
             
             : 
      


*/
class Solution
{
public:
    int *findTwoElement(int *arr, int n) 
    {
        int complete_xor=0,arr_xor=0,tot_xor=0;
        for(int i=1;i<=n;i++)
        {
            complete_xor^=i;
            arr_xor^=arr[i-1];
        }
        tot_xor = complete_xor ^ arr_xor;
        
        //seperate the missing number and repeting number from total_xor
        
        int till=(log(n)/log(2))+1,bit;
        
        for(int i=0;i<=till;i++)
        {
            if( ((1<<i) & tot_xor)!=0){bit=i;break;}
        }
        
        int buck1=0,buck2=0;

        for(int i=1;i<=n;i++)
        {
          if( ((1<<bit) & i) !=0 ) buck1^=i;
          else buck2^=i;
          if( ((1<<bit) & arr[i-1]) !=0 )buck1^=arr[i-1];
          else buck2^=arr[i-1];
        }
        int ok=0;
        for(int i=0;i<n;i++)
        {
            if(buck1==arr[i]){ok=1;break;}
        }
        int *ans=new int[2];
        if(ok==1)
        {
          ans[0]=buck1;
          ans[1]=buck2;
        }
        else  
        {
          ans[0]=buck2;
          ans[1]=buck1; 
        }
        return ans;
    }
};

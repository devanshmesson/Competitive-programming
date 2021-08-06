/*
Problem Link - https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Solution 1  - Sort the array ,  Time- O(NLogN) Space - O(1)
Soultion 2 - Hashing , Time - (O(2*N)), Space - O(N)
Solution 3 - Using XOR , Time - O(5*N), Space - O(1)

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
             
             9.To acomplish the task in point 8, lets think about (4th point of XOR property).
               9.1 So we have to find a bit(ith) that is set in 4.
               9.2 We have to find a number which has ith bit set and another number which has ith bit not-set.
               9.3 To do this, we should look at all such possibilities which satisfies 9.2
               9.4 To look at all possibilities , Divide the range[1 to n] in two buckets.
               9.5 One bucket has numbers(from range [1-n] ) which has ith bit set and another bucket has numbers(from range [1-n]) which has ith bit not-set.
               9.6 Now we have the numbers,rather than trying all possibilities,we should ommit those n-2 numbers which were discussed in point 1.
               9.7 These n-2 numbers are not part of either duplicate number and repeted number so they must be Omitted by XORRING them with the numbers in the buckets.
               9.8 After you ommit those n-2 numbers you are left with two numbers , one in each bucket which your ANSWER!!
               
               9.9 Let me take an example of the above steps from 9.1 to 9.8
                   9.9.1 Result after XORRING in point 7 was 4.
                   9.9.2 2nd bit in 4 is set.If x^y=4,then x is a number which has 2nd bit set and y is a number which has 2nd bit not set.
                   9.9.3 Its obvious that missing number and duplicate number are from the range [1 to 6]
                   9.9.4 Looking at all possibilites by diving the range [1 2 3 4 5 6] into two buckets.Refer 9.5
                   9.9.5 Bucket-1 contains [4 5 6] AND bucket-2 contains [1 2 3]
                   9.9.6 Rather than trying out all possibilities by taking a pair,(each number from both buckets), we should first ommit
                         those n-2=4 numbers.Those 4 numbers were 2 3 4 6.
                   9.9.7 Dividing these 4 numbers and XORRING them to ommit.
                   9.9.8 Bucket-1 contains [4 4 5 6 6] AND bucket-2 contains [1 2 2 3 3]
                   9.9.9 After Xorring all numbers of Bucket-1, it contains a number 5.
                   9.9.10 After Xorring all numbers of Bucket-2, it contains a number 1.
                   9.9.11 You Got your 2 numbers which are the answers to your question.
                   
            10.To figure which of these numbers is the missing number and which of these is the duplicate number , you can check it by traversing the given array.
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

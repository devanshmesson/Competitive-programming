/*
Problem Link - https://leetcode.com/problems/maximum-subarray/
Expected time complexity - O(n)
Expected space comeplexity  -O(1)

-------------------------------------------------
Solution 1 : O(n^3) approach [Bruteforce]
Generate all (n)*(n+1)/2 subsets.~ O(n^2)
iterate each subset. ~O(n)

Total time complexity - O(n^2) * O(n) = O(n^2)
-------------------------------------------------
Solution 2 : O(n^2) [Bruteforce]
generate all (n)*(n+1)/2 subsets. ~ O(n^2)
Sum the numbers while generating them and keeping track the maximum sum. O(1)

Total time complexity - O(n^2) * O(n) = O(n^2)
------------------------------------------------
Solution 3: O(n) [Kadane's algorithm]

-Keep adding the elements one by one in a variable 'sum'. ~ O(n)
-Keep updating the maximum sum. ~O(1)
-while adding, if the sum < 0: then make sum=0 and start counting the sum from from next element. ~O(1)
*/
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
       int sum=0,maxi=INT_MIN;
       for(int i=0;i<nums.size();i++)
       {
          sum+=nums[i];
          maxi=max(maxi,sum);
          if(sum<0)sum=0;
       }
       return maxi;
    }
};

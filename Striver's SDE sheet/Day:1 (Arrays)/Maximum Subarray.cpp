/*
Problem Link - https://leetcode.com/problems/maximum-subarray/
Expected time complexity - O(n)
Expected space comeplexity  -O(1)

-------------------------------------------------
Solution 1 : O(n^3) approach [Bruteforce]
Generate all (n)*(n+1)/2 subsets.~ O(n^2)
iterate each subset. ~O(n)

Total time complexity - O(n^2) * O(n) = O(n^3)
-------------------------------------------------
Solution 2 : O(n^2) [Bruteforce]
generate all (n)*(n+1)/2 subsets. ~ O(n^2)
Sum the numbers while generating them and keeping track the maximum sum. O(1)

Total time complexity - O(n^2) * O(n) = O(n^2)
--------------------------------------------------------------------------------------------------------------------------------------
Solution 3 : O(n*Log n) [Merge Sort ~   Divide and Conquer]

Let mid be the middle element of the array (l+r/2),l=first element,r=last element
Idea is that subbarray sum can be situated at:
a)Left part of the array ~ [l,mid]
b)Right part of the array~ [mid+1,r]
c)Centre of the array ~ some elements are in left part and some are in right part.

Keep dividing the array into two halves until the size of the array becomes 1.
when size of subarray becomes one, left sum , right sum, centres sum = that element.

How Left sum and right sum are actually calculated :  
As previously dicussed , when size of subarray becomes one, left sum , right sum, centres sum = that element.
Suppose this element is the left child of a subarray : then for that parent subarray, left sum is it's left child's max sum.
Same goes for right sum as  well.
This way,it (Left sum, Right sum, Centre sum) goes upwards.(Recursively)

Parent subarray's left part's sum is the maximum (left sum ,right sum, centre sum) of it's left child.
Parent subarray's right part's sum is the maximum (left sum ,right sum, centre sum) of it's right child.
Parent subarray's centre part's sum is :
maximum continuous sum in left part staring from mid'th element + maximum continuous sum in right part staring from mid+1 'th element.

An array's maximum subarray sum is calculated as  Maximum(left sum ,right sum, centre sum) of the array.

Explaination regarding the centre part sum:

Let A = Maximum continuous sum in left part of the array starting from mid element.
Let B = Maximum continuous sum in right part of the array starting from mid+1 'th element.
let low = first element of the array
let high= last element of the array.
So, CSS for an array is calculated as: A + B

Q - why are we starting from the mid'th element ? 
Ans -  because CSS means the centre of the array which eventually means that some elements of subarray having maximum sum are in the left part of array and some elements of subarray having maximum sum  are in the right part of the array.

Suppose, If we compute maximum continuous sum in the order from low to mid (or high to mid+1) then suppose if first element is the subarray having maximum sum, then this method is wrong because this subarray will not be linked to the subarray having maximum sum in the right part of the array.

In short we have to link both maximum subarray in left part as well as right part to make it crossing sum subarray(CSS).

For example array is  7, -6, 5, 4, -2, 1
(Considering 0 based indexing)

index of mid element = 2 
value of mid element = 5

A will computed as :
Keep adding every element one by one starting from mid element :and keep track of the maximum sum

Sum=0
Sum= sum + 5 ,     , sum=5 , A = 5
Sum = Sum + (-6) , sum=-1,  A =5
Sum = Sum + 7 ,     sum=6 , A = 6 
Subarray having  maximum continuous sum in left part of the array  : [7, -6, 5]

B will computed as :
Keep adding every element one by one starting from mid element :and keep track of the maximum sum

Sum=0
Sum= sum + 4,     , sum=4, B = 4
Sum = Sum + (-2) , sum=2,  B =4
Sum = Sum + 7 ,     sum=3 , B = 4
Subarray having maximum continuous sum in right part of the array  : [4]

SO, CSS for the array [7, -6, 5, 4, -2, 1]  =  [7, -6, 5, 4]

Note :  if you start the counting of the sum from the right most part of the array (r) then value of B will be less.
Demonstration of the above argument:

Sum=0
Sum= sum + 1,     , sum=1, B = 1
Sum = Sum + (-2) , sum=-1,  B =1
Sum = Sum + 4 ,     sum=3 , B = 3

So, this proves that CSS should be calculated from the mid element.

------------------------------------------------------------------------------------------------------------------------------------------

Solution 4: O(n) [Kadane's algorithm]

-Keep adding the elements one by one in a variable 'sum'. ~ O(n)
-Keep updating the maximum sum. ~O(1)
-while adding, if the sum < 0: then make sum=0 and start counting the sum from from next element. ~O(1)
*/


//-----------------------------------------------------------------------------------------------------------------------------------------
//Code for Solution 4

class Solution 
{
public:
    int max1,sum,max2;
    int maxSubArray(vector<int>& nums) 
    {
        return recur(0,nums.size()-1,nums);
    }
    
    int recur(int l,int r,vector<int>&nums)
    {
     if(l<r)
     {
      int mid=(l+r)/2;
      int left_sum=recur(l,mid,nums);
      int right_sum=recur(mid+1,r,nums);
      max1=INT_MIN,sum=0,max2=INT_MIN;
      for(int i=mid;i>=l;i--){sum+=nums[i]; max1=max(max1,sum);}
      sum=0;
      for(int i=mid+1;i<=r;i++){sum+=nums[i]; max2=max(max2,sum);}
      max1=max(max1+max2,max(left_sum,right_sum));
     }
     else max1=nums[l];
     return max1;
    }
};

//----------------------------------------------------------------------------------------------------------------------------------------
//Code for Solution 4
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

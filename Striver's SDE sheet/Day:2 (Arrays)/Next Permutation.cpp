/*
Problem Link - https://leetcode.com/problems/next-permutation/submissions/
Solution:1
Generate all permuatations of the array and search for the input array in all permutations, and just print the permutation just ahead of the input array.
Time complexity - O(n! * n)

Solution:2
Condition for Lexicographically next permuatation is:
let there be two arrays: 
1.a1,a2,----,an
2.b1,b2,----,bn

Array a will be Lexicographically next permuatation of Array b when there will be:
Till Largest index -1 all elements of array a equals all elements of array b, and a[largest index] > b[largest index].

1.We have to find that "largest index" and place a greater value in place of previous value.This greater value should be found at indexes greater than largest index.
because before largest index array must be same as mentioned in the condition.

2.To find largest index, traverse the array from end and find the 1st index such that a[i]<a[i+1].Reason - The 1st index from end will be the largest index from the start.
Reason for the condition (a[i]<a[i+1]) is because, we have to find an element which has greater value than the value at largest index.After the largest index, 
the aray will surely be in decreasing order, and in decreasing order, we cant find a largest index because there will exist no index(say, i) at which we find a greater element than
the element at index less than i, so permutation cannot happen in such a way as needed in the problem statement because in decreasing order, the permutation is already lexicographically largest.

For example, take array 1 3 5 4 2
Largest index would be 1 (0-based indexing) which has value=3. 3 can be replaced by a greater value which exist after 1st index.

FOR UNDERSTANDING PURPOSES:
If you select 3 as the largest index, will you be able to replace a larger value in place of value=4? No, because only 2 is left after value=4 which is < 4. If you
replace 4 with 2, then the permuatation generated will be lexicographically smaller, which is incorrect accorsing to the question.

3.Now, we have to find the smallest value which is greater than value at index 1(value=3).Reason for selecting smallest value which is greater than the value=3 is because
we have to find the permutation which is just next to the current permutation.

For example, if value at index 2 is replaced by value at index 1.
array will be as follows: 1 5 3 4 2
But this array is not the next permutation for the array 1 3 5 4 2.


4.We will find the smallest value which is greater than value at index 1 by traversing the aray from end and find the first value is greater than the value at index 1.
This first value will replace the value at index 1.Reason for traversing the array from the end is because as we discussed earlier that after the largest index, the 
array is in decreasing order from left to right, which means that array is in increasing order after largest index if we see it from end(right to left).So, 
first value which is greater than value at index 1 would be the smallest value possible.

For example,
If we traverse from end, value at index 3 is greater than value at largest index(1st index).
smallest value which is greater than value at index 1 = 4

5.Swap the value at index 1 and the smallest value which is greater than value at index 1.This array is not our final answer yet.This array is lexicographically greater than
the input array but it's not the next permutation, because the array is in decreasing order after the largest index which makes the array lexicographically much larger than
the real answer. So, reverse the part of array from (largest index +1) to the end of array(this part is in decreasing order,so make it increasing by reversing it).

For example, 
Swapping value at largest index(1st index) and value at index 3 which was greater tha value at index 1.
Now, array becomes, 1 4 5 3 2
Part of array after largest index is 5 3 2 (which is decreasing)

6.As soon as it gets reversed, now the array is our final answer because, the value replaced at largest index is the smalles possible and secondly the array 
after the largest index is in increasing order, so it is lexicographically next permutation.

For example, 
Now final array looks like , 1 4 2 3 5

Time complexity - O(3*n), 
1.one loop for finding largest index
2.one loop for finding the smallest value greater than value at largest index
3.One loop for reversing the part of the array.

CORNER CASE:
if whole array is in decreasing order, then there exists no largest index at whicb a[i] < a[i+1]
In that case, the input array is lexicographically the largest permutation possible, so, Reversed input array will be the final answer, because reversed input array
is lexicographically smallest possible permutation.
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
      //Search for largest index which will decide whether the next array is next permuted array or not.
      //Travere from the reverse to find the index i, at which ar[i] < ar[i+1]
      int sz=nums.size();
      int breakpoint=-1;
      for(int i=sz-2;i>=0;i--)
      {
          if(nums[i]<nums[i+1]){breakpoint=i; break;}
      }
      
      if(breakpoint==-1)
      {
         int half=sz/2;
         for(int i=0;i<half;i++)swap(nums[i],nums[sz-1-i]); 
      }
      else
      {
          
        /*Search for the next greater element than nums[breakpoint], keep in mind that next greater element
        is to be found after breakpoint, reason being, condition of lexicogrpahical order says that
        Elements till (breakpoint-1)th index remain same and (breakpoint)th index will create the difference between lexicographically smaller and next permuted array*/
      
       int need;
       for(int i=sz-1;i>=0;i--)
       {
           if(nums[i]>nums[breakpoint]){need=i;break;}
       }
      
        /*This nums[need] will be creating the difference between lexicographically smaller and next permuted array, nums[need] will come in place of nums[breakpoint]*/
      
       swap(nums[need],nums[breakpoint]);
      
       /*Now, array becomes lexicographically greater than the input array, but it's not the next permuted array, To make it next permuted array, sort the part of the array from (breakpoint+1)th index till 
       end of the array because this array will now rank lower than what is was previously and we will get exactly next permuted array*/
      
       /*Instead of sorting, we can reverse that part of array because the part will always be in decreasing order, because breakpoint index was the first index from reverse having condition of
       increasing order, but after the (breakpoint)th index, the part of the array is in decreasing order*/
       
        int half=(sz-breakpoint-1)/2;
        for(int i=breakpoint+1;i<=(breakpoint+half);i++)
        {
            swap(nums[i],nums[sz+breakpoint+1-i-1]);
        }
      }
    }
};

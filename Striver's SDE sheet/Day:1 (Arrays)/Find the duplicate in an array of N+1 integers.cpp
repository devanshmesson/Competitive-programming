/*Problem Link : https://leetcode.com/problems/find-the-duplicate-number/
Required Time Complexity - O(n)
Required Space Complexity - O(1)
----------------------------------------------------------------------------------SOLUTION--------------------------------------------------------------------------------
Solution-Floyd's Tortoise and Hare Method OR Cycle Detection Method

1.Let array's name is arr.
2.Start from the first number in the arr and move to the arr[first number] do this until you find a arr[x] which will be found again and eventually which will make a cycle.
3.We take two pointers : Fast pointer and slow pointer
4.Let H be the point at which fast pointer and slow pointer are initially standing (starting point of the array).
5.Fast pointer moves 2 steps and slow pointer moves 1 step.
6.These 2 pointers will meet if there is a cycle.
7.Let M be the point where these two pointers meet.
8.After These two pointers meet , place the fast pointer to H.
9.Move the fast pointer as well as slow pointer one step.
10.The point where these two pointers meet for the second time is the duplicate number.
11.These two pointers meet for the second time iff,they both are equidistant from the 2nd meeting point.
12.Let S be the point from where the cycle begins Or in other words , the point which is the duplicate number Or in other words,
point where two pointers meet for the second time.

---------------------------------------------------------------------------------ASSUMPTIONS---------------------------------------------------------------------------------------------------
Distance from H to S = x1 (following arrows)
Distance from S to M = x2 (following arrows)
Distance from M to S = x3 (following arrows)

Let a = x1 + x2
-----------------------------------------------------------------------------------PROOF1--------------------------------------------------------------------------------
Fast pointer will travel double the distance as compared to slow pointer.
->Proof:

How Fast pointer travelled  : 
-> x1 + x2 + x3 + x2  (one cycle = x2 + x3)
-> x1 + x2 + one cycle
-> a + once cycle

How Slow pointer travelled  : 
-> x1 + x2
-> a

As Fast pointer is travelling one cycle extraas compared to slow pointer so Fast pointer will travel double the distance as compared to slow pointer
to meet at M.

-----------------------------------------------------------------------------------PROOF2--------------------------------------------------------------------------------

Proof of the fact that "they both are equidistant from the 2nd meeting point (Fast pointer is at H and Slow pointer is at M)
In other words , we  have to prove that , Distance from H to S = Distance from M to S
In other words , we  have to prove that , x1 = x3

2*(Distance travelled by slow ptr) = Distance travelled by fast ptr
2x1 + 2x2 =  x1 + x2 + x3 + x2
2x1  =  x1  + x3 
x1 = x3

MOREOVER we can say , 
How Fast pointer travelled  : x1 + x2 + one cycle 
                            : x3 + x2 + one cycle (x1=x3)
                            : one cycle + once cycle (one cycle = x3 + x2)
                            : two cycles
                           
How Slow pointer travelled  : x1 + x2 
                            : x3 + x2 (x1=x3)
                            : one cycle (one cycle = x3 + x2)
                            : one cycle
                            
Hence,Fast pointer will travel double the distance as compared to slow pointer.
------------------------------------------------------------------------------------END-------------------------------------------------------------------------
*/

class Solution 
{
    public:
    int findDuplicate(vector<int>& nums) 
    {
        int slow=nums[0],fast=nums[0];
        while(1)
        {
          slow=nums[slow];
          fast=nums[nums[fast]];
          if(slow==fast)break;
        }
        fast=nums[0];
        while(1)
        {
          if(slow==fast)return slow;
          slow=nums[slow];
          fast=nums[fast];
        }
    }
};

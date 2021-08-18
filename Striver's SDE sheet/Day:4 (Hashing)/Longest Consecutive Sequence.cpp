/*
Problem Link - https://leetcode.com/problems/longest-consecutive-sequence/
Solution:1
1.Store all the elements in unordered_map, to check whether an element exists or not.
2.Traverse the array, and keep on incrementing the current element, if the incremented element is there in the array(check through unordered_map), then increase the 
count variable, and return the maximum count out of all the counts for each element in the array.

Time complexity - O(n^2)
Space complexity - O(n)

Solution:2
1.Sort the array
2.If adjacent elements are consecutive, then increase the count, and find the max count.

Time complexity - O(nLogn)
Space complexity - O(1)

Solution:3
1.This is an efficient and smart way of implementing the Solution:1.
2.Instead of incrementing every element, Only those elements should be incremented which are first element of the list of consecutive elements.
3.In other words, only those elemennts should be incremented which does not have their previous consecutive element(which means first in the list.)
4.No need to count for the element, which has (element-1) in the array, because this will not be the maximum count as (element-1) will not be counted, because we are increasing the current element.
5.Through this, entire algorithm will be running only 2n times.

Proof of point 5:
1 2 3 4 5 7, n=6

(a)iterator is at 1, (1-1) is not present in the array, so, 1->2->3->4->5->6, 1 is incremented to 2, 
which exists and it keeps on going till 6, where 6 was not in the array(last iteration).Sequence count = 5
(b)iterator is at 2,(2-1) is present in the array, so no need to increment, because we already calculated for 1.
(c)iterator is at 3,(3-1) is present in the array, so no need to increment, because we already calculated for 1.
(d)iterator is at 4,(4-1) is present in the array, so no need to increment, because we already calculated for 1.
(e)iterator is at 5,(5-1) is present in the array, so no need to increment, because we already calculated for 1.
(f)iterator is at 7,(7-1) is not present in the array, so, 7->8, Sequence count=1.

Total iterations for (a) = 1+5(1 for the outer loop and 5 for the inner loop)
Total iterations for (b) = 1(1 for the outer loop)
Total iterations for (c) = 1(1 for the outer loop)
Total iterations for (d) = 1(1 for the outer loop)
Total iterations for (e) = 1(1 for the outer loop)
Total iterations for (f) = 1+1(1 for the outer loop and 1 for inner loop)

Total iterations for whole algorithm - 12, which is n*2(where n=6).

Basically the iterations for consecutive list is being repeated(like here, 2 3 4 5 got repeated), rest all element who has element-1 present in the array have only one iterations.

Time complexity - O(n)
Space complexity - O(n)




*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<long long int,int>mp;
        int n=nums.size(),maxi=INT_MIN;
        if(n==0)return 0;
        for(int i=0;i<n;i++)mp[nums[i]]=1;
        for(int i=0;i<n;i++)
        {
            long long int previous_number=nums[i]-1;
            if(mp[previous_number]==1)continue;
            long long int start=nums[i]+1;
            int count=1;
            while(mp[start]==1)
            {
                count++;
                start++;
            }
            maxi=max(maxi,count);
        }
        if(maxi==INT_MIN)maxi=1;
        return maxi;
    }
};

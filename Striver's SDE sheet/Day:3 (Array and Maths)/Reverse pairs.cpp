/*
Problem Link - https://leetcode.com/problems/reverse-pairs/
Solution is same as this problem (Count inversions)- https://github.com/devanshmesson/Competitive-programming/blob/master/Striver's%20SDE%20sheet/Day:2%20(Arrays)/Count%20inversions.cpp

Change - 
Multiply the right array in the merge function by 2 and perform the exact function, without reflecting in the "nums" array.This will take an extra O(n) loop.
Normal merge operation will take another O(n) Loop.

Time complexity - O(2nLogn)
Space complexity - O(3n)



*/
class Solution {
public:
    int merge(int low,int mid,int high,vector<int>& nums)
    {
        long long int left[mid-low+1],right[high-mid];
        for(int i=low;i<=mid;i++)left[i-low]=nums[i];
        for(int i=mid+1;i<=high;i++)right[i-mid-1]=nums[i];
        int ptr1=0,ptr2=0,index=low;
        int reverse_pair=0;
        while(ptr1<=(mid-low) && ptr2<=(high-mid-1))
        {
            if(left[ptr1]<=right[ptr2])
            {
                nums[index]=left[ptr1];
                ptr1++;
            }
            else 
            {
                nums[index]=right[ptr2];
                ptr2++;
            }
            index++;
        }
        
        while(ptr1<=(mid-low)){nums[index]=left[ptr1];ptr1++;index++;}
        while(ptr2<=(high-mid-1)){nums[index]=right[ptr2];ptr2++;index++;}
        long long int temp_right[high-mid];
        for(int i=0;i<=(high-mid-1);i++){temp_right[i]=2*right[i];}
        ptr1=0,ptr2=0;
         while(ptr1<=(mid-low) && ptr2<=(high-mid-1))
         {
            if(left[ptr1]<=temp_right[ptr2])ptr1++;
            else 
            {
                reverse_pair+=(mid-low-ptr1+1);
                ptr2++;
            }
         } 
        return reverse_pair;
    }
    int merge_sort(int low,int high,vector<int>& nums)
    {
        int ans=0;
        if(low<high)
        {
            int mid=(low+high)/2;
            ans+=merge_sort(low,mid,nums);
            ans+=merge_sort(mid+1,high,nums);
            ans+=merge(low,mid,high,nums);
        }
        return ans;
    }
    int reversePairs(vector<int>& nums) 
    {
        return merge_sort(0,nums.size()-1,nums);
    }
};

//https://leetcode.com/problems/sliding-window-maximum/

/*
Performed Sliding window approach.
Maintain a deque, which contains the maximum element of a window at its front.
Why the max element(maxi) is at front?
Because all the previous elements before maxi which are smaller than maxi will be removed from
the deque, because they dont have any use in the future windows.

Deque will always have elements in decreasing order.
Deque is used because, we can remove the elements from the front and back in O(1).

If a smaller element comes after a comparitively bigger element, then 
we will push the smaller element.

Why?
Because this smaller element is useful in the future windows. Because
when the bigger element will get popped out, then this smaller element can be a candidate 
for the max element in a future window.

When ith element enters the deque, its the last element to decide the max element for window
which starts from (i-k+1)th index.

TC - O(N)
SC - O(K)

*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
      deque<int>dq;
      vector<int>ans;
      int n=nums.size();
      if(k>n)return ans;
      for(int i=0;i<k;i++)
      {
         while(!dq.empty() && nums[i]>nums[dq.back()])dq.pop_back();
         dq.push_back(i);
      }
      ans.push_back(nums[dq.front()]);
      for(int i=k;i<n;i++)
      {
        //Remove the elements which dont belong to this window.
        if(!dq.empty() && (i-k)==dq.front())dq.pop_front();
        //Remove the previous smaller elements because its of no use.
        while(!dq.empty() && nums[i]>nums[dq.back()])dq.pop_back();
        //Now push the current element.
        dq.push_back(i);
        ans.push_back(nums[dq.front()]);
      }
      return ans;
    }
};

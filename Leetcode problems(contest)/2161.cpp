//https://leetcode.com/problems/partition-array-according-to-given-pivot/
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot)
    {
        vector<int>aa,bb,cc;
  for(auto x: nums)
  {
    if(x<pivot)aa.push_back(x);
    else if(x==pivot)bb.push_back(x);
    else cc.push_back(x);
  }

  vector<int>ans;
  for(auto x: aa)ans.push_back(x);
  for(auto x: bb)ans.push_back(x);
  for(auto x: cc)ans.push_back(x);
  return ans;

    }
};

//https://leetcode.com/problems/gray-code/

/*
For N=1, answer is [00,01]
For N=2, answer can be built as:
Add a unset bit at the starting of the all the numbers belonging to answer of (N-1) as follows:
000
001

Add a set bit at the starting of the all the numbers belonging to answer of (N-1) as follows:
100
101

Merge these two answers, but there is problem if we merge them in a straight way:


*/
class Solution 
{
public:
    vector<int> grayCode(int n) 
    {
      vector<int>ans;
      if(n==1)return {0,1};
      ans=grayCode(n-1);
      int addbit=(1<<(n-1));
      vector<int>temp;
      for(int i=(1<<(n-1))-1;i>=0;i--)ans.push_back(addbit+ans[i]);
      return ans;  
    }
};

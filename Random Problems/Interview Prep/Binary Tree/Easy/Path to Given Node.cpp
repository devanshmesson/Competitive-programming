//https://www.interviewbit.com/problems/path-to-given-node/

/*
Run a DFS,keep pushing the current node in the vector, if we find the node, return true,If node is NULL we return false.
and if left or right subtree returns false, which means node not found, then backtracking will be done,
So, remove the last node added from the vector.
if left or right subtree returns true, which means node got found, now we will not remove the last node added to the vector.

vector will be passed as reference, in orer to ensure that vector remians same in recursion call backs, basically we can control the vector if we pass
through reference. If we pass by value then recursion will handle the vector.

TC - O(N)
SC - O(N)
*/
bool getpath(TreeNode *node,vector<int>&ans, int B)
{ 
  if(node==NULL)return false;
  ans.push_back(node->val);
  if(node->val==B)return true;
  bool left=getpath(node->left,ans,B);
  bool right=getpath(node->right,ans,B);
  if(left|right)return true;
  else {ans.pop_back(); return false;}
}
vector<int> Solution::solve(TreeNode* A, int B) 
{
 vector<int>ans;
 getpath(A,ans,B);
 return ans;
}

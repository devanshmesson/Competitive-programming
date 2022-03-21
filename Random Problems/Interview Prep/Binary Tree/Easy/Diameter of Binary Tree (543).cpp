//https://leetcode.com/problems/diameter-of-binary-tree/
/*
TC-O(N)
SC-O(N)
Let x = (sum of heights of left subtree and right subtree of a node - 2).
Calculate x for all nodes and return maximum x.
*/
class Solution 
{
public:
    int ans=0;
    int dia(TreeNode* root)
    {
      if(root==NULL)return 0;
      int left=1+dia(root->left);
      int right=1+dia(root->right);
      ans=max(ans,left+right-2);
      return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL)return 0;
        dia(root);
        return ans;
    }
};

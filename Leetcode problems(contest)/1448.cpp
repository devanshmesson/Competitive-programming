/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
    public:
    int cnt=0;
    void dfs(TreeNode* n, int maxi)
    {
      cnt+=((n->val)>=maxi);
      maxi=max(maxi,n->val);
      if(n->left!=nullptr)dfs(n->left,maxi);
      if(n->right!=nullptr)dfs(n->right,maxi);
    }
    int goodNodes(TreeNode* root) 
    {
      dfs(root,root->val); 
      return cnt;
    
    }
};

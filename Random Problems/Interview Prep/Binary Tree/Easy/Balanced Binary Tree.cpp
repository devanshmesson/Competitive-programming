//https://leetcode.com/problems/balanced-binary-tree/

/*
TC- O(N)
SC- O(N)
If the height of left subtree and right subtree of the root has a difference > 1, then its not a balanced binary tree, because if a middle node is not
satisfying the condition, that means, the overall height of that subtree(left or right) got increased.

Moreover, this is checking every node's left subtree and right subtree.
*/
class Solution 
{
public:
    int flag=1;
    int check(TreeNode *root)
    {
        if(root==NULL)return 0;
        int left=1+check(root->left);
        int right=1+check(root->right);
        if(abs(right-left)>1)flag=0;
        return max(left, right);
    }
    bool isBalanced(TreeNode* root) 
    {
      if(root==NULL)return true;
      check(root);
      return flag;
    }
};

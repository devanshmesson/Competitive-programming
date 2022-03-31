//https://leetcode.com/problems/insert-into-a-binary-search-tree/

/*
Just attach the node to the leaf node's right, if leaf node's value < value of attached node.
Else attach the node to the leaf node's left, if leaf node's value > value of attached node.

So, just traverse till the leaf node.Go through the path as if the attached node's value is supposed to be there and just attach it there.

TC - O(LOGN)
SC -O(1)
*/
class Solution 
{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
      if(root==NULL)return new TreeNode(val);
      TreeNode *temproot=root;
      while(root)
      {
          if(val<root->val)
          {
              if(!root->left){root->left=new TreeNode(val);break;}
              root=root->left;
          }
          else 
          {
              if(!root->right){root->right=new TreeNode(val);break;}
              root=root->right;
          }
      }
      return temproot;
        
    }
};

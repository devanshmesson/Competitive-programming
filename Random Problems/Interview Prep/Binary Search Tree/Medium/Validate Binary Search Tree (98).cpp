//https://leetcode.com/problems/validate-binary-search-tree/

/*
Recursive
Run a DFS, provide every node a range, if this node does not lie in the range, return false.
Root of the tree has a range[LONG_MIN,LONG_MAX].
left part of range states that node's value should be greater than it.
Right part of range states that node's value should be lesser than it.

If we are going to node's left, you are ensuring that nodes's left should be lesser than node.
So, change the range to [l,node's value], left part remains the same, because surely, node's left 
would be present in the right subtree of any of it's ancestor which has a value l, which requires node's left value
to have it's value greater than l.

If we are going to node's right, you are ensuring that nodes's right should be greater than node.
So, change the range to [node's value,r], right part remains the same.because surely, node's right 
would be present in the left subtree of any of it's ancestor which has a value r, which requires node's right value
to have it's value lesser than r.

TC -O(N)
SC - O(N) DUE TO RECURSION.
*/

class Solution 
{
public:
    bool checkbst(TreeNode *root, long int l, long int r)
    {
        if(root==NULL)return true;
        if(root->val<=l || root->val>=r)return false;
        bool checkleft=checkbst(root->left,l,root->val);
        bool checkright=checkbst(root->right,root->val,r);
        return (checkleft & checkright);
    }
    bool isValidBST(TreeNode* root) 
    {
      long int l=LONG_MIN,r=LONG_MAX;
      return checkbst(root,l,r);
    }
};

/*
Iterative:
Perform an Inorder Morris traversal and check if Inorder traversal is sorted or not by Just maintaining a variable(let say, cur) 
and update it with the present root's value, and before updating cur, just check if the current root's value is less than equal to the  cur. 
If yes, then the Binary Tree is not a BST.

TC - O(N)
SC - O(1)
*/
class Solution 
{
public:
    bool isValidBST(TreeNode* root) 
    {
     int first=0,cur;
     bool isbst=true;
     while(root)
     {
         if(root->left==NULL)
         {
            if(first && root->val <= cur && isbst)isbst=false;
            if(first==0)first=1;
            cur=root->val;
            root=root->right;
         }
         else
         {
             //Finding the rightmost node in the left subtree of the root
             TreeNode *traverse=root;
             traverse=traverse->left;
             while(traverse->right && traverse->right!=root)traverse=traverse->right;
             if(!traverse->right){traverse->right=root; root=root->left;}
             else
             {
                  if(root->val <= cur && isbst)isbst=false;
                  cur=root->val;
                  traverse->right=NULL;
                  root=root->right;
             }
         }
     }
     return isbst;
    }
};

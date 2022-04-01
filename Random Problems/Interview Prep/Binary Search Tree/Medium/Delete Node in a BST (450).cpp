//https://leetcode.com/problems/delete-node-in-a-bst/

/*
If a node(X) needs to be deleted, Leftmost node's left pointer of right subtree of X should point to root of left subtree of X. Parent
of X should point to root of right subtree of X.

If node to be deleted is Root.Do the same thing as above, except the concept of parent.
Some corner cases are like - if left subtree is NULL, then simply connect parent of X to root of right subtree of X.
                           - if right subtree is NULL, then simply connect parent of X to root of left subtree of X.
                           
If these corner cases occur when root is to be deleted, then just simply return the other subtree.If right is NULL, return left and vice versa.
*/
class Solution 
{
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
      if(root==NULL)return NULL;
      //If root needs to be deleted
      if(root->val==key)
      {
          //Corner cases
          if(!root->right)return root->left;
          if(!root->left)return root->right;
           //Connect the root of left subtree of X to the leftmost node of the right subtree of X,
           //Here, X is the node to be deleted.
          TreeNode *newroot=root->right,*cur=root->right;
          while(cur->left){cur=cur->left;}
          cur->left=root->left;
          root->left=root->right=NULL;
          return newroot;  
      }
      TreeNode *parent,*temproot=root;
      //if ch is 'L', that means, node to be deleted is left child of it'a parent
      //if ch is 'R', that means, node to be deleted is right child of it'a parent
      char ch;
      while(root)
      {
         if(root->val==key)
         {
           //Corner cases, when right subtree is NULL or left subtree is NULL
           TreeNode *connect_subtree=NULL;
           if(!root->right)connect_subtree=root->left;
           if(!root->left)connect_subtree=root->right;
           if(connect_subtree)
           {
             if(ch=='L')parent->left=connect_subtree;
             if(ch=='R')parent->right=connect_subtree;
             break;
           }
           //General Case, when both subtrees exists
           //Connect parent of node to be deleted to right of root.
           if(ch=='L')parent->left=root->right;
           if(ch=='R')parent->right=root->right;
           //Connect the root of left subtree of X to the leftmost node of the right subtree of X,
           //Here, X is the node to be deleted.
           TreeNode *cur=root->right;
           while(cur->left){cur=cur->left;}
           cur->left=root->left; 
           root->left=root->right=NULL;
           break;
         }
         if(key<root->val){ch='L';parent=root;root=root->left;}
         else if(key>root->val){ch='R';parent=root;root=root->right;}
      }
      return temproot;
        
    }
};

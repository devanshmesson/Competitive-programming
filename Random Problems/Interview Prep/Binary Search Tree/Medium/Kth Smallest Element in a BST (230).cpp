//https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/*
Inorder traversal of BST is an array sorted in the ascending order.
So, Just perform an inorder traversal on the BST.
In, Recursive(virtual stack) and Iterative(stack), we have to use extra space.
So, perform a morris traversal, which uses O(1) extra space. 

Just decrement K as we foind the root. when k gets to 0.return the root's value.

Follow up:  Find Kth largest element.
Approach -  First do any traversal to find total number of nodes in the tree, let say n.
Then kth largest element is the (n-k+1)th smallest element.
So, perform morris inorder traversal and this time k = (n-k+1). Rest algo remains same.

TC - O(N)
SC - O(1)
*/
class Solution 
{
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        int ksmall;
        while(root)
        {
            if(root->left==NULL)
            {
             k--; 
             if(k==0){ksmall=root->val;}
             root=root->right;
            }
            else
            {
              TreeNode *traverse=root;
              //Finding the rightmost node in the left subtree
              traverse=traverse->left;
              while(traverse->right && traverse->right!=root)traverse=traverse->right;
              if(!traverse->right)
              {
               traverse->right=root; 
               root=root->left;
              }
              else 
              {
                  k--; 
                  int y=root->val;
                  if(k==0)
                  {ksmall=root->val;} 
                  traverse->right=NULL;root=root->right;}
              
            }
        }
        return ksmall;
    }
};

//https://leetcode.com/problems/recover-binary-search-tree/

/*
Observation: Inorder Traversal of a BST is a sorted sequence. If in the BST, two nodes are exchanged, one node's val will be bigger 
than the other node's val. If the nodes are not exchanged, then inorder of that BST is sorted, but if the nodes are exchanged, that means
inorder is unsorted.Because a bigger node was swapped with a smaller node, In the inorder sequence,
Now bigger node is in the position of smaller node, and smaller node is in the position of bigger node, which means
index of bigger node in the inorder sequence < index of smaller node in the inorder sequence.

That means, if we traverse the inorder sequence and find the first node(ith index) which is greater than it's next node((i+1)th index), than 
this first node is one of the two nodes which were swapped.

If we traverse further in the inorder sequence, there will be another node(jth index) which is smaller than its previous node((j-1)th node).
this node at jth index is one of the two nodes which were swapped.


So, we will swap the values of node at ith index and node at jth index.

Corner case - j=i+1, which means, The swapped nodes were adjacent in inorder traversal.In that case, second node will be NULL
So we will save the (i+1)th node for for the first node, if in case, second node is NULL, then first and its adjacent will be swapped.

Instead of storing the inorder traversal, we can perform a morris traversal, and store the previous node.
Now check if the root is smaller than prev, if its the first time, this condition came true, then First node(one of two swapped nodes) will saved as the prev node.Prev node
is the bigger node.if its the second time, this condition came true, then second node(one of two swapped nodes) will saved as the root node.root node
is the smaller node.

TC - O(N)
SC - O(1)
*/
class Solution 
{
public:
    TreeNode *first=NULL,*second=NULL,*adjacent=NULL, *prev=NULL;
    void store_violation(TreeNode *root)
    {
        if(prev && root->val < prev->val)
        {
          if(!first)
          {
            adjacent=root;
            first=prev; 
          }
          else second=root;
        } 
    }
    void recoverTree(TreeNode* root)
    {
      while(root)
      { 
          if(root->left==NULL)
          {
              store_violation(root);
              prev=root;
              root=root->right;
          }
          else 
          {
              TreeNode *traverse=root->left;
              //Finding the rightmost node in the left subtree of the root and connect it to root.
              while(traverse->right && traverse->right!=root)traverse=traverse->right;
              if(!traverse->right){traverse->right=root; root=root->left;}
              else 
              {
               store_violation(root);
               prev=root;
               traverse->right=NULL; 
               root=root->right;
              }
          }
      }
      if(!second){swap(first->val,adjacent->val);}
      else swap(first->val,second->val); 
    }
};

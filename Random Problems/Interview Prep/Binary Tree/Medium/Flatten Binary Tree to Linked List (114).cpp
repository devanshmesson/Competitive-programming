//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/*
Because Preorder traversal is ROOT LEFT RIGHT, So the linked list should be connected in such a way that
Root should be connected to First Node of Preorder traversal of left subtree of the root in the form of linked list .
Last Node of Preorder traversal of left subtree of the root in the form of linked list should be connected to
First Node of Preorder traversal of right subtree of the root in the form of linked list.

Observation: to connect a node(a) to another node(b). We first need the node b to get assigned to node a.
Just like that, the flattened preorder traversal for right subtree should be ready to get connected 
to the flattened preorder traversal for left subtree.

To do this, We traverse in reverse preorder fashion which Right, left, root. First right subtree of root is made ready to get connected to
left subtree. A prev pointer is used to store the first node of the preorder traversal of right subtree.As soon as right is ready, we go to left.
The last node(rightmost) of the left subtree's right pointer gets connected to prev and left pointer gets pointed to NULL, prev gets 
updated to this node.

To understand it more clearly, start with a root, having only one node on left and one node on right.
Then gradually increase the tree, you will get it!

TC - O(N)
SC - O(N)
*/
class Solution 
{
public:
    TreeNode *prev=NULL;
    void flatten(TreeNode* root) 
    {
      if(root)
      {
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
      }
    }
};

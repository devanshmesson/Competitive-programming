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
The last node (rightmost) of the left subtree's right pointer gets connected to prev and left pointer gets pointed to NULL, prev gets 
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

/*
Iterative:
Observation : last node(rightmost) of the left subtree of any node gets connected to the first node of the right subtree.

We will use stack.So, first node of right subtree should be before the last node of left subtree.Stack contains root initially.
Start from root. Push the right child , then push the left child. Now connect the root's right to the left child and 
root's left to NULL.Then in next iteration, pick the top element. which will the left child of it's root.
If it's left child & right child  is NULL, then this is the left most node of it's root.So, the next top element
is the right child of the root that we are talking about. So now this leftmost node gets connected to the top element 
which is the first right element.

TC - O(N)
SC - O(N)


*/
class Solution 
{
public:
    void flatten(TreeNode * root) 
    {
      
      stack<TreeNode*>s;
      if(root)s.push(root);
      while(!s.empty())
      {
        TreeNode *root=s.top();
        s.pop();
        if(root->right)s.push(root->right);
        if(root->left)s.push(root->left);
        if(!s.empty())root->right=s.top();
        root->left=NULL;
      }
    }
};
/*
Perform Morris Traversal.
Observation : last node(rightmost) of the left subtree of any node gets connected to the first node of the right subtree.
For a node, go to its rightmost node in its left subtree. Rightmost node in code means, go left and then go extreme right. If extreme right node contains
left, then dont go there. Just connect the extreme right to the node's right.After that, Connect the root's right ptr to root' left node. and connect root's
left pointer to NULL.and for further traversal, go to root's right. So basically, as we are traversing, er are flattening it.

Reason for not going to left after extreme right is reached, is because
When extreme right becomes the "node"(basically, root), then its subtree's extreme right will be connected to the node' right which is eventually,
the right node of root of whole tree.So, the right gets updated till the last node. And what about the root which was also connected to the 
right node of root of whole tree? This right ptr is now pointing to it's left node. So this how it works.

TC - O(N)
SC - O(1)
*/

class Solution 
{
public:
    void flatten(TreeNode * root) 
    {
      while(root)
      {
          if(root->left)
          {
              TreeNode *traverse=root;
              traverse=traverse->left;
              while(traverse->right)traverse=traverse->right;
              traverse->right=root->right;
              root->right=root->left;
              root->left=NULL;
          }
          root=root->right;
      }
    }
};

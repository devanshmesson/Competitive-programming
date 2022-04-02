//https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1/#


/*
Approach 1
Store the inorder traversal in a vector.
Lineary travese the vector to find next greater element than value of node x. 
We can also do a binary search and find next greater element than value of node x.

TC- O(N)
SC -O(N)
*/


/*
Approach 2
Do a Morris inorder traversal, and while traversing, as soon as we find the first element greater than node x value.The node
with this element is our answer.

TC - O(N)
SC - O(1)
*/



/*
Approach 3
Inorder successor of a node(x) in BST is just a node having the value next greater than value of x, which is basically
calculating ceil of the value of node x with just a small change that dont consider the value of x as ceil

TC - O(Height)
SC - O(1)
*/
class Solution
{
  public:
      Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node *ceil=NULL;
        while(root)
        {
            if(x->data < root->data){ceil=root; root=root->left;}
            else root=root->right;
        }
        return ceil;
    }
};

//https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1/#


/*
Approach 1
Store the inorder traversal in a vector.
Lineary travese the vector to find next greater element than value of node x. 
We can also do a binary search and find next greater element than value of node x.

TC- O(N)
SC -O(N)
*/
class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    
    Node * inOrderSuccessor(Node *root, Node *x)
    {
       Node *suc=NULL;
       vector<pair<int,Node*>>inorder;
       while(root)
       {
         if(root->left==NULL){inorder.push_back({root->data,root});root=root->right;} 
         else 
         {
           //Finding the rightmost node in the left subtree of the root and connecting it to root.
           Node *traverse=root;
           //going to left
           traverse=traverse->left;
           //going to extreme right
           while(traverse->right && traverse->right!=root)traverse=traverse->right;
           if(!traverse->right){traverse->right=root; root=root->left;}
           else {inorder.push_back({root->data,root}); traverse->right=NULL; root=root->right;}
          }  
       }
      //Binary search
       int l=0,r=inorder.size()-1,mid;
       int ans=-1;
       while(l<=r)
       {
           mid=(l+r)/2;
           if(inorder[mid].first<=x->data)l=mid+1;
           else {r=mid-1; ans=mid;}
       }
       if(ans==-1)return NULL;
       return inorder[ans].second;
    }
    
};



/*
Approach 2
Do a Morris inorder traversal, and while traversing, as soon as we find the first element greater than node x value.The node
with this element is our answer.

TC - O(N)
SC - O(1)
*/
class Solution{
  public:
    
    Node * inOrderSuccessor(Node *root, Node *x)
    {
       Node *suc=NULL;
       while(root)
       {
         if(root->left==NULL){if(root->data > x->data && !suc)suc=root; root=root->right;} 
         else 
         {
           //Finding the rightmost node in the left subtree of the root and connecting it to root.
           Node *traverse=root;
           //going to left
           traverse=traverse->left;
           //going to extreme right
           while(traverse->right && traverse->right!=root)traverse=traverse->right;
           if(!traverse->right){traverse->right=root; root=root->left;}
           else {if(root->data > x->data && !suc)suc=root; traverse->right=NULL; root=root->right;}
          }  
       }
       return suc;
    }
    
};



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

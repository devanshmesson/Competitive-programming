//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

/*
Observation - Perform solution of two-sum problem on the inorder traversal of the BST.

Solution of two sum problem in a sorted array:
ith pointer points to 0th index, jth pointer points to last index,let required sum be "sum"
if (val[i]+val[j])==sum, return true
if (val[i]+val[j])>sum, j--
else i++

A Naive solution will be to implement Morris Inorder traversal and store the inorder traversal in a vector and just do two sum problem.
TC - O(N)
SC - O(N)
*/
class Solution 
{
public:
    stack<TreeNode*>in_next,in_before;
    bool hasnext(){return !in_next.empty();}
    bool hasbefore(){return !in_before.empty();}
    void update_next_stack(TreeNode *root) { while(root){in_next.push(root);root=root->left;} }
    void update_before_stack(TreeNode *root){while(root){in_before.push(root);root=root->right;}}
    int next()
    {
       TreeNode *next_element=in_next.top();
       in_next.pop();
       update_next_stack(next_element->right);
       return next_element->val;
    }
    int before()
    {
       TreeNode *before_element=in_before.top();
       in_before.pop();
       update_before_stack(before_element->left);
       return before_element->val;
    }
    bool findTarget(TreeNode* root, int k) 
    {
      update_next_stack(root);
      update_before_stack(root);
      int i=next(),j=before();
      while(hasnext() && hasbefore())
      {
         int sum=i+j;
         if(sum==k && i!=j)return true;
         if(sum>k)j=before();
         else i=next();
      }
      return false;
        
    }
};

/*
Observation - Perform solution of two-sum problem on the inorder traversal of the BST.

Solution of two sum problem in a sorted array:
ith pointer points to 0th index, jth pointer points to last index,let required sum be "sum"
if (val[i]+val[j])==sum, return true
if (val[i]+val[j])>sum, j--
else i++

We can use the idea of BST iterator to know the next() and before() in the inorder traversal.
If we know the next() and before(), then can apply two sum problem.Basically, next() means i++ and before() means j--
next() will return the next value in the inorder traversal(starting from 0th index of inorder) and before will return the previous value
(starting from last index of inorder).

We are saving space here, which is O(Height of tree)
For next(), we will save the nodes on the extreme left path of the root.If a node backtracks we will move to right and save the 
nodes on the extreme left path of the root.

For before(), we will just do opposite of next(), that is, RIGHT ROOT LEFT. we will save the nodes on the extreme right path of the root.
If a node backtracks we will move to left and save the 
nodes on the extreme left path of the root.
*/
class BST_iterator
{
    public:
    stack<TreeNode*>inorder;
    bool isnext=true;
    BST_iterator(TreeNode *root,bool init_nextval)
    {
       isnext=init_nextval;
       update_stack(root);
    }
    void update_stack(TreeNode *root)
    {
       while(root)
       {
           inorder.push(root);
           if(isnext)root=root->left;
           else root=root->right;
       }
    }
    int next()
    {
      TreeNode *nextnode=inorder.top();
      inorder.pop();
      if(isnext)update_stack(nextnode->right);
      else update_stack(nextnode->left);
      return nextnode->val;
    }
    
};
class Solution 
{
public:
    bool findTarget(TreeNode* root, int k) 
    {
      BST_iterator i(root,true), j(root,false);
      int a=i.next(),b=j.next();
      while(a<b)
      {
         int sum=a+b;
         if(sum==k && a!=b)return true;
         if(sum>k)b=j.next();
         else a=i.next();
      }
      return false;  
    }
};

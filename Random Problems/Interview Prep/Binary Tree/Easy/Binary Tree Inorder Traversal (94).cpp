//https://leetcode.com/problems/binary-tree-inorder-traversal/

/*
Recursive
TC - O(N)
SC - O(N)
*/
class Solution 
{
public:
    vector<int>ans;
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if(root==NULL)return ans;
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
        return ans;
    }
};

/*
Iterative
If top is not null, Keep On adding the top's left node to stack, else, remove the top(null), print the value of the top, pop off the top,
then push top's right element. Repeat.

TC -O(N)
SC - O(N)
*/
class Solution 
{
public:
    
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>ans;
        if(root==NULL)return ans;
        stack<TreeNode*>s;
        s.push(root);
        while(1)
        {
           if(s.top()==NULL)
           {
              s.pop();
              if(s.size()==0){break;}
              ans.push_back(s.top()->val);
              TreeNode *rightchild=s.top()->right;
              s.pop();
              s.push(rightchild);
           }
           else
           {
               s.push(s.top()->left);
           }
        }
      
        return ans;
    }
};

/*
Morris Traversal (Iterative)
Explanation written in notes.
TC - O(N)
SC-O(1)
*/
class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
      vector<int>inorder;
      while(root)
      {
          if(root->left==NULL)
          {
             inorder.push_back(root->val);
             root=root->right;
          }
          else
          {
             TreeNode *traverse=root;
             //Connecting the rightmost node in the left subtree of root to the root.
             traverse=traverse->left;
             //Second condition is necessary for the case when node is backtracked  from its rightmost node.
             while(traverse->right && traverse->right!=root)
             {
               traverse=traverse->right;
             }
              
             if(traverse->right==NULL)
             {
                traverse->right=root;
                root=root->left;
             }
             else
             {
                 //backtracking from rightmost node in the left subtree of root to the root, breaking the link too, because its no more needed.
                 traverse->right=NULL;
                 inorder.push_back(root->val);
                 root=root->right;
             }
              
          }
      }
        return inorder;
    }
};

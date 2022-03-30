//https://leetcode.com/problems/binary-tree-preorder-traversal/

//Recursive
class Solution 
{
public:
    vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if(root==NULL)return ans;
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ans;
    }
};

//Iterative
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
Think how virtual stack of recusrion works, and you just have to do it in same way in iteration.
When too element is popped off, push right element in stack and then push the left element, 
why? because, after popping off the left element, it should backtrack and print the right child.
*/
class Solution 
{
public:
    
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int>ans;
        if(root==NULL)return ans;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *node=s.top();
            ans.push_back(node->val);
            s.pop();
            if(node->right)s.push(node->right);
            if(node->left)s.push(node->left);
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
    
    vector<int> preorderTraversal(TreeNode* root) 
    {
     vector<int>preorder;
      while(root)
      {
          if(root->left==NULL)
          {
             preorder.push_back(root->val);
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
                preorder.push_back(root->val);
                traverse->right=root;
                root=root->left;
             }
             else
             {
                 //backtracking from rightmost node in the left subtree of root to the root, breaking the link too, because its no more needed.
                 traverse->right=NULL;
                 root=root->right;
             }
          }
      }
        return preorder;
    }  
};

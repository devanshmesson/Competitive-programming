//https://leetcode.com/problems/binary-tree-inorder-traversal/

//Iterative
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
Recursive
If top is not null, Keep On adding the top's left node to stack, else, remove the top(null), print the value of the top, pop off the top,
then push top's right element. Repeat.
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

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

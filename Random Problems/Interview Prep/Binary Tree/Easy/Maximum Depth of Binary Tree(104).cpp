//https://leetcode.com/problems/maximum-depth-of-binary-tree/

/*
Performed Level Order Traversal(BFS)
TC - O(N)
SC - O(N)
*/
class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        if(root==NULL)return NULL;
        queue<TreeNode*>q;
        q.push(root);
        int depth=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *curnode=q.front();
                q.pop();
                if(curnode->left)q.push(curnode->left);
                if(curnode->right)q.push(curnode->right);
            }
            depth++;
        }
        return depth;
        
    }
};

/*
Performed Recursion
If you are standing at the root, recursively call 1+left subtree, 1+ right subtree, return the max ans;
TC - O(N)
SC - O(N)
*/
class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        if(root==NULL){return 0;}
        return max(1+maxDepth(root->left),1+maxDepth(root->right));
    }
};

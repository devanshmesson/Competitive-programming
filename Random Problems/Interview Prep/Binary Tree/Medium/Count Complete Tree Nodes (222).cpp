//https://leetcode.com/problems/count-complete-tree-nodes/

/*
Run a dfs, Start from root, if left height and right height is same, that means its a full binary tree, Number 
of nodes in a full binary tree is (2^height)-1. If if left height and right height is not same, current node
will contribute 1 and then go left and then go right.Repeat the process.

Basically, we are finding full binary subree in the given tree, this stop us from traversing every node.
At max, we will traverse the whole height (Log N) leftwards, in other words, every bpundary node will
contribute 1, and right subtree of every boundary node will be a full binary tree, so we dont need to traverse all
nodes.

TC - o(Log(n) * Log(n)) because, at max we traverse whole height, so at each boundary node we are also calculating height of
left subtree and height of right subtree, which takes another Log N time.

SC - O(Log(n)) -  at max O(LogN) recursive calls.


*/
class Solution 
{
public:
    pair<bool,int> isfull(TreeNode *root)
    {
        int leftheight=0,rightheight=0;
        TreeNode *temp=root;
        while(root){leftheight++; root=root->left;}
        root=temp;
        while(root){rightheight++; root=root->right;}
        return {leftheight==rightheight,(1<<leftheight)-1};
    }
    int countNodes(TreeNode* root) 
    {
      if(root==NULL)return 0;
      pair<bool,int>p=isfull(root);
      if(p.first)return p.second;
      else return 1 + countNodes(root->left) + countNodes(root->right); 
    }
};

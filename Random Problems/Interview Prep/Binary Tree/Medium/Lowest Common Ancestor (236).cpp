//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/*
TC - O(N)
SC - O(N)
Store the parent node, as well as level of parent node, for all the nodes. 
Observation - if both nodes are at same level, then if they simultaneously move to their
parents, then at on point of time, their parents will become same, so the first time
when their parents become same, thats the LCA.


So, if level of parent of p and parent of q are not same, then first
move the node with bigger level, to the same level as of node with smaller node.
If the nodes gets equal here, then return this as the lca.

Then do as said in observation.
*/
class Solution 
{
public:
    void dfs( map<TreeNode*, pair<TreeNode*,int>>&prev, TreeNode *root, int level)
    {
        if(root->left){prev[root->left]={root,level}; dfs(prev,root->left,level+1);}
        if(root->right){prev[root->right]={root,level}; dfs(prev,root->right,level+1);}
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        map<TreeNode*, pair<TreeNode*,int>>prev;
        prev[root].first=NULL;
        dfs(prev,root,1);
        TreeNode *big,*small;
        if(prev[p].second>prev[q].second){big=p,small=q;}
        else {big=q,small=p;}
        int diff=abs(prev[p].second-prev[q].second);
        while(prev[big].first!=NULL && diff--) big=prev[big].first;
        if(big==small)return big;
        while(prev[big].first!=prev[small].first)
        {
            big=prev[big].first;
            small=prev[small].first;
        }
        return prev[big].first;
    }
};

/*
TC - O(N)
SC - O(N) due to recursion
Run a DFS, if cur node is either p or q or null, so return cur node 
to its parent node.Suppose this cur node was from left & cur node was p.
then parent will go its right, if now, cur node is q. then cur node will be
returned to its parent. 

At one time during dfs, one of the nodes will get 1 node returned from
left and 1 node returned from right.That means, the cur node is the LCA.
so return this cur node to its parent node, eventually, it gets returned to
the root, and root returns the LCA.

If a node gets a node returned only from one of the sides, then the returned node
will be returned to the cur node's parent.NULL will never be taken into consideration.

If p is in subtree of q, then it will never happen that nodes will get 1 node returned from
left and 1 node returned from right. One of the nodes will always return NULL. In that case,
The returned node will be the LCA.
*/
class Solution 
{
public:
    TreeNode* dfs(TreeNode *root, TreeNode* p, TreeNode* q)
    {
      if(root==p || root==q || root==NULL)return root;
      TreeNode *left=dfs(root->left,p,q);
      TreeNode *right=dfs(root->right,p,q);
      if(left && right)return root;
      return (left)?(left):(right);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
       if(p==root || q==root)return root;
       if(p==q)return p;
       return dfs(root,p,q);
    }
};

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

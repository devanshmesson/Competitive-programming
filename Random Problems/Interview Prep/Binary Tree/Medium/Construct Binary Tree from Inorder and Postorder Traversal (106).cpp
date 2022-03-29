//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

/*
*/
class Solution 
{
public:
    map<int,int>root_pos;
    TreeNode* build_tree(vector<int>& inorder, vector<int>& postorder,int post_start,int post_end,int in_start, int in_end)
    {
        
       if(post_start > post_end || in_start > in_end)return NULL;
       int root=postorder[post_end];
       int root_position=root_pos[root];
        
       int rightnodes=in_end-root_position;
       int leftnodes=root_position-in_start;
       TreeNode *newnode=new TreeNode(postorder[post_end]);
       
       newnode->right=build_tree(inorder,postorder,post_end-rightnodes,post_end-1,root_position+1,root_position+rightnodes);
       newnode->left=build_tree(inorder,postorder,post_start,post_start+leftnodes-1,in_start,root_position-1);
       return newnode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
     for(int i=0;i<inorder.size();i++)root_pos[inorder[i]]=i;
     int post_start=0,post_end=postorder.size()-1,in_start=0,in_end=inorder.size()-1;
     return build_tree(inorder,postorder,post_start,post_end,in_start,in_end); 
    }
};

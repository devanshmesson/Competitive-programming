//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/*
Complete it, refer leetcode editorial!
*/

class Solution 
{
public:
    int ptr=0;
    void build_tree(TreeNode *root, vector<int>&preorder, vector<int>&inorder, int l, int r, char child)
    {
      if(l<=r && ptr<inorder.size())
      {
         int mid;
         int found=0;
         for(int i=l;i<=r;i++)
         {
             if(inorder[i]==preorder[ptr])
             {
                 ptr++;
                 mid=i;
                 found=1;
                 break;
             }
         } 
         if(found)
         {
             TreeNode *newroot=new TreeNode(inorder[mid]);
             if(child=='l')root->left=newroot;
             else root->right=newroot;

             build_tree(newroot,preorder,inorder,l,mid, 'l');
             build_tree(newroot,preorder,inorder,mid+1,r,'r');  
         }
      }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
       TreeNode *root=new TreeNode();
       build_tree(root,preorder,inorder,0,inorder.size()-1,'l');
       return root->left;
    }
};

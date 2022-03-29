//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/*
The two key observations are:

1.Preorder traversal follows Root -> Left -> Right, therefore, given the preorder array preorder, we have easy access to the root which is preorder[0].
2.Inorder traversal follows Left -> Root -> Right, therefore if we know the position of Root, we can recursively split the entire array into two subtrees.
 
In preorder, current element should be assumed as the root.This element is first checked if its on the left of its root.If not, it gets checked
on the right side of root.Here inorder sequence helps us to fid the root and also check whether the element is on the left/right of the root.

So, preorder[0] is the root of whole tree. This root will be found out in the inorder traversal and then inorder sequence gets divided into
2 parts, left and right.Then preorder[1] is assumed to be the root and left of it's root. So, find preorder[1] on the left side of the inorder.
If not found, It will go to the right side.Increment the pointer of preorder sequence, when it found, otherwise dont.
This process is done recursively, until whole preorder sequence is traversed.
*/

class Solution 
{
public:
    int ptr=0;
    TreeNode* build_tree(vector<int>&preorder, vector<int>&inorder, int l, int r,map<int,int>&root_pos)
    {
      if(l>r)return NULL;
      int root_position=root_pos[preorder[ptr++]];
      TreeNode *newroot=new TreeNode(inorder[root_position]);
      newroot->left=build_tree(preorder,inorder,l,root_position-1,root_pos);
      newroot->right=build_tree(preorder,inorder,root_position+1,r,root_pos);
      return newroot;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
       TreeNode *root=new TreeNode();
       map<int,int>root_pos;
       for(int i=0;i<inorder.size();i++)root_pos[inorder[i]]=i;
       return build_tree(preorder,inorder,0,inorder.size()-1,root_pos);
    }
};

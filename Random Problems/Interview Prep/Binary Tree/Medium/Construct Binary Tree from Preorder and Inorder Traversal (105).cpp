//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/*
1.Root node of whole tree is the first element of tbe preorder sequence.
2.Find the root in the inorder sequence, the elements on the left of the root index are the elements contained in the left subtree and 
  the elements on the right of the root index are the elements contained in the right subtree of the root.
3.Once the root node is found, we can recurse down on the right and left subtrees, i.e., right subarray and left subarray split at
respective root index to repeat the same process until we find at most a single element in either sub-array.Attach root's left to
the root of the left subtree and Attach root's right to the root of the right subtree.
4.So, the left recursive call will contain, its inorder sequence and preorder sequence and right recursive call will contain
  its inorder sequence and preorder sequence. So this became a new problem. So just start from point 1. This is how 
  recursion is working.
  

TC - O(NLOGN)
SC - O(N)
*/

class Solution 
{
public:
    map<int,int>root_pos;
    TreeNode* build_tree(vector<int>&preorder, vector<int>&inorder,int pre_start,int pre_end,int in_start, int in_end)
    {
      if(pre_start>pre_end)return NULL;
      //Finding the root
      int root=preorder[pre_start];
      //Finding the root position in order
      int root_position=root_pos[root];
      //finding number of nodes in the left subtree of root.
      int leftnodes=root_position-in_start;
      //Making node for the root
      TreeNode *newroot=new TreeNode(preorder[pre_start]);
      newroot->left=build_tree(preorder,inorder,pre_start+1,pre_start+leftnodes,in_start,root_position-1);
      newroot->right=build_tree(preorder,inorder,pre_start+leftnodes+1,pre_end,root_position+1,in_end);
      return newroot;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
       for(int i=0;i<inorder.size();i++)root_pos[inorder[i]]=i;
       int pre_start=0,pre_end=inorder.size()-1,in_start=0,in_end=inorder.size()-1;
       return build_tree(preorder,inorder,pre_start,pre_end,in_start,in_end);
    }
};

//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

/*
1.the root node of whole tree is the last element of tbe postorder sequence.
2.Find the root in the inorder sequence, the elements on the left of the root index are the elements contained in the left subtree and 
  the elements on the right of the root index are the elements contained in the right subtree of the root.
3.Once the root node is found, we can recurse down on the right and left subtrees, i.e., right subarray and left subarray split at
respective root index to repeat the same process until we find at most a single element in either sub-array. 
*/
class Solution 
{
public:
    map<int,int>root_pos;
    TreeNode* build_tree(vector<int>& inorder, vector<int>& postorder,int post_start,int post_end,int in_start, int in_end)
    {        
       if(post_start > post_end)return NULL;
       //root node
       int root=postorder[post_end];
       //finding root node in inorder sequence
       int root_position=root_pos[root];
       //Number of nodes in the left subtree of the root
       int leftnodes=root_position-in_start;
       //Creating a node for the current root.
       TreeNode *newnode=new TreeNode(postorder[post_end]);
       //Build the right subtree of root, by calling the right subarray of postorder sequence[post_start+leftnodes,post_end-1] & inorder sequence
       //[root_position+1,in_end]
       newnode->right=build_tree(inorder,postorder,post_start+leftnodes,post_end-1,root_position+1,in_end);
       //Build the left subtree of root, by calling the left subarray of postorder sequence[post_start,post_start+leftnodes-1] & inorder sequence
       //[in_start,root_position-1]
       newnode->left=build_tree(inorder,postorder,post_start,post_start+leftnodes-1,in_start,root_position-1);
       //when the left & right subtrees are built, return this new root, to its root.
       return newnode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
     for(int i=0;i<inorder.size();i++)root_pos[inorder[i]]=i;
     int post_start=0,post_end=postorder.size()-1,in_start=0,in_end=inorder.size()-1;
     return build_tree(inorder,postorder,post_start,post_end,in_start,in_end); 
    }
};

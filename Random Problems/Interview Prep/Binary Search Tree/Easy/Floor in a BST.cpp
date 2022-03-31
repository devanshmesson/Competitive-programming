//https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=1

/*
If node's value is equal to x, then return x.
If node's value is lesser than x, update the floor and go to it's right.As we will go on the right side of node, we dont need to maximize floor explicitly,
It will already have a greater number, if this conditions appears again in future.
If node's value is greater than x,go to node's left.
TC - O(LogN), Travelling the height of tree which is at max Log N in almost all cases. 
SC - O(1)
*/
int floorInBST(TreeNode<int> * root, int X)
{
    int floor=-1;
    while(root)
    {
        if(root->val==X)return X;
        if(X > root->val){floor=root->val; root=root->right;}
        else root=root->left;
    }
    return floor;
}

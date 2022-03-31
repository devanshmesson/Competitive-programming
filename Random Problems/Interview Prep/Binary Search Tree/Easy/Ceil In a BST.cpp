//https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0

/*
If node's value is equal to x, then return x.
If node's value is greater than x, update the ceil and go to it's left.As we will go on the left side of node, we dont need to minimize ceil explicitly,
It will already have a lesser number, if this conditions appears again in future.
If node's value is lesser than x,go to node's right.

TC - O(LogN), Travelling the height of tree which is at max Log N in almost all cases. 
SC - O(1)
*/

int findCeil(BinaryTreeNode<int> *node, int x)
{
    int minimum=-1;
    while(node)
    {
        if(node->data==x)return x;
        if(x<(node->data)){minimum=node->data; node=node->left;}
        else node=node->right;
    }
    return minimum;  
}

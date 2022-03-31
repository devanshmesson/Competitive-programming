//https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0

/*
If node's value is equal to x, then return x.
If node's value is greater than x, then save it in a variable, and keep on finding the minimum greater element every time this type of
condition occurs.go to node's left
If node's value is lesser than x,go to node's right.

TC - O(LogN), Travelling the height of tree which is at max Log N in almost all cases. 
SC - O(1)
*/

int findCeil(BinaryTreeNode<int> *node, int x)
{
    int minimum=2e9;
    while(node)
    {
        if(node->data==x)return x;
        if(x<(node->data)){minimum=min(minimum,node->data); node=node->left;}
        else node=node->right;
    }
    return (minimum==2e9)?-1:minimum;  
}

//https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos

/*
  If parent value < sum of its children values, assign sum(children's value) to parent. (1)
  If parent value > sum of its children values, assign parent's value to both children. (2)
  now, go it left and right node of cuurent node.
  do the same thing as mentioned above, because now current node's children's value can be updated, so if there is some update required
  for parent, then do it.
  
  This is for sure, that, after traversing left and right, the current node's children's value will always be greater than it was before, 
  Reason being, if (1) satisfies, the value will increase, if (2) satisfies, value remains same.
  
  why (2) works?
  when children will backtrack, (1) will satisfy for sure, and parent's value will become equal to its sum(children's value).
  
  And, No node will be less than its original value.
  
  TC - O(N)
  SC - O(N)
*/
void change_values(BinaryTreeNode <int>**root)
{
        int sum=0;
        if((*root)->left)sum+=(*root)->left->data;
        if((*root)->right)sum+=(*root)->right->data;
        if(sum > (*root)->data)(*root)->data=sum;
        else if(sum < (*root)->data)
        {
             if((*root)->left)(*root)->left->data=(*root)->data ;
             if((*root)->right)(*root)->right->data=(*root)->data ;
        }
}
void changeTree(BinaryTreeNode < int > * root)
{
    if(root && (root->left || root->right))
    {
        change_values(&root);
        if(root->left)changeTree(root->left);
        if(root->right)changeTree(root->right);
        change_values(&root);
    }
}  

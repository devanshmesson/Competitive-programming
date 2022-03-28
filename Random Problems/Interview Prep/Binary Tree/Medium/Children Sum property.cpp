https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos
int fetch(BinaryTreeNode <int> * temp)
{
   if(temp!=NULL)return temp->data;
   else return 0;
}
void change_values(BinaryTreeNode <int>**root)
{
        int sum=fetch((*root)->left) + fetch((*root)->right);
        if(sum > (*root)->data)(*root)->data=sum;
        else if(sum < (*root)->data)
        {
             int leftsum=((*root)->data - sum);
             if(fetch((*root)->left) && fetch((*root)->right))
             {
              (*root)->left->data += (leftsum/2);
              int addon=0;
              if(leftsum%2)addon=1;
              (*root)->right->data += (leftsum/2) + addon;
             }
             else if(fetch((*root)->left))(*root)->left->data=(*root)->data ;
             else if(fetch((*root)->right))(*root)->right->data=(*root)->data ;
        }
}
int change(BinaryTreeNode <int>**root)
{
    if( (*root)->left || (*root)->right )
    {
        change_values(root);
        if(fetch((*root)->left))change(&(*root)->left);
        if(fetch((*root)->right))change(&(*root)->right);
        change_values(root);
    }
}
void changeTree(BinaryTreeNode < int > * root)
{
  if(root)change(&root);    
}  

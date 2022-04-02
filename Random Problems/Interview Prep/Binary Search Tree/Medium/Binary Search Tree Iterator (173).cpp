//https://leetcode.com/problems/binary-search-tree-iterator/
/*
Idea-
Inorder traversal goes to extreme left from the root, the extreme left is it's inorder sequence next element,
and then it backtracks to it's root, prints it and go to it's right, then it again go extreme left and now this node is it's next inorder sequence, so
it prints it and backtracks and it repeats till the end.

Why it goes extreme left? In BST, extreme left node is the smallest next node.Because Inorder traversal ia sorted sequence, the 
next element must be the smallest among all future nodes.

Why it goes right and then extreme left? Inorder sequence, the flow is LEFT,ROOT,RIGHT.So, when we come to the next smaller element, in order
traversal, it means that this is the root, and it has completed its left subtree, thats why it is here and now, it has go to its right.
The moment it goes right, Left Root Right applies here as well, so it goes to extreme left to find next smaller element.

Let H be the height of the tree.
We will use stack for this task. Stack will contain at max H elements at a time. Stack will contain, All the 
elements of the extreme left side nodes of the root.Initially, stack will contain the left boundary of BST. The top 
of the stack contains the first element of inorder traversal.If next() function gets called, it will return the top of the stack and pop it and 
check if it has a right subtree or not. If yes, then stack inserts the right node of the top of the stack we just returned, and then inserts
extreme left path nodes till the end. If you imagine, Inorder Traversal works the same way.

TC -O()
SC - O(Height of the tree)



*/
class BSTIterator 
{
public:
    stack<TreeNode*>inorder;
    BSTIterator(TreeNode* root) 
    {
      update_stack(root);
    }
    int next() 
    {
      TreeNode *next_element=inorder.top();
      inorder.pop();
      //next_element is the root, it has completed its left, now it goes to it's right subtree's extreme left
      update_stack(next_element->right);
      return next_element->val;
    }
    bool hasNext() 
    {
      return !inorder.empty();
    }
    void update_stack(TreeNode *root)
    {
      while(root){inorder.push(root); root=root->left;}  
    }
};

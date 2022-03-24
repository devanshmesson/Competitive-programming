//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

/*
Perform a level order traversal with a small change.If leftToright=1, then push back the ith element of queue in the ith index of temp vector.
Else, push ith element of the queue in the (size_of_temp-i-1)th position, in order to reverse the original order.
*/
class Solution 
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
       vector<vector<int>>ans;
       if(root==NULL)return ans;
       queue<TreeNode*>q;
       q.push(root);
       int leftToright=1;
       while(!q.empty())
       {
           int size=q.size();
           vector<int>temp(size);
           for(int i=0;i<size;i++)
           {
               TreeNode *node=q.front();
               q.pop();
               if(leftToright)temp[i]=(node->val);
               else temp[size-i-1]=node->val;
               if(node->left)q.push(node->left);
               if(node->right)q.push(node->right);
           }
           leftToright=!leftToright;
           ans.push_back(temp);
       }
       return ans;
        
    }
};

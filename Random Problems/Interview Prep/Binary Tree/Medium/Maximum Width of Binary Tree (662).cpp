//https://leetcode.com/problems/maximum-width-of-binary-tree/


/*
Perform a level order traversal, and provide indexes to each node. WIDTH of a particalar level = index of last node - index of first node.
Calculate width for all levels and return the maximum.

Indexing will be done as the same way we do for binary trees indexing, like start from 1(root), left node becomes 2*parent, right node
becomes 2*parent+1. It also cover NULL values in between, thats why the formula of width is working.

Corner case (overflow):
In leetcode, it is said that answer will always be in limits of int, but some corner cases there where overflow can happen.
1. A large scew tree (only child).In this, values be exponentially increase and will overflow after the height becomes 31.In this,
Only one node is there at each level, so there is no need of such large values.
2. A tree with only two nodes, the left node goes rightwards and right node goes leftwards. Difference will bw 2, but values 
will keep on increasing. For example at height 30th, the values of two nodes is 1610612735(left) & 1610612736(right), 
having a difference of 2 (1610612735-1610612736+1). There is no need of such large values.

3.A large scew tree, after that any kind of tree starts growing. the starting point of tree will be huge, which does not make sense.
because the scew tree having large values is un-neccessary.

For taking there of these conditions:
At each level, subtract the minimum value from the cuurent node you are at. Why?

Suppose, you had 2 nodes, 1535(left) & 1536(right), so left's left = 3071, and right's right = 3072, having difference again as 2.
Observation, if there two values a and b, diff= a*2 - b*2 = (a-b)*2. 

So,  according to our approach, the large value(last) of a level will be become (max-min) and smallest value(first) of each level,
will become 0. This will work for further levels too using the same observation.

This hack will help us reduce the unecessary large values by maintaining the correct difference between them.

For a normal tree, like left going leftwards and right going rightwards, its of no use, because only left will become 0, but right will
exponentially become greater. 

left will 2^exp, so right will be 2^(exp+1).
left=0, right=right-left = 2^(exp)


TC - O(N)
SC - O(N)
*/
class Solution 
{
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,1});
        long long int  maxi=1;
        int cnt=0;
        while(!q.empty())
        {
            cnt++;
            int size=q.size();
            long long int min_=q.front().second;
            long long int max_=q.back().second;
            maxi=max(maxi, max_-min_+1);
            for(int i=0;i<size;i++)
            {
              TreeNode *node=q.front().first;
              long long int number=q.front().second;
              q.pop();
              number-=min_;
              if(node->left){q.push({node->left, number*2}); }
              if(node->right){q.push({node->right,number*2+1});}
            }

        }
        return maxi;
    }
  
};

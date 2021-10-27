/*
link - https://leetcode.com/problems/delete-node-in-a-linked-list/

Solution:1
Let x be the position of node to be deleted
Copy the (x+1)th node value to xth node value, increment x, and do this until the second last value of list is not modified, and 
at last, point the second last node to NULL.

Time complexity - O(n), where n is the length of list.

Solution:2
Let x be the position of node to be deleted.
Copy the (x+1)th node value to xth node value.
point the xth node to (x+2)th node.

Time complexity - O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Solution:1
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        while(node->next->next!=NULL)
        {
            node->val=node->next->val;
            node=node->next;
        }
        node->val=node->next->val;
        node->next=NULL;
    }
};


//Solution:2
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};

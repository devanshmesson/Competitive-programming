/*
Link  - https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Solution:1
1.Traverse the list to calculate size of the list.
2.Let nth node be the node from end of the lost which needs to be deleted.
3.Again, traverse the list till the (size-n)th node and link the previous node of nth node and next node of nth node.

Time complexityv - O(2*n)

Solution:2
1.By only traversal, the problem will be solved.
2.size - n = x, where xth node is the node from starting of the list which needs to be deleted.
3. rearrange the formula, size=n+x.
4.Take one pointer(fast) and traverse it till nth node, the left number of nodes = x.
5.Take a slow pointer at head and simultaneously traverse fast and slow pointer by one node, as soon as fast pointer reaches last node, the position 
of slow pointer is at the node (n-1)th node.

for example,
List = [1,2,3,4,5]
n=2

fast pointer traversed till 2.
Iteration:1
slow pointer at 1, fast pointer at 3
Iteration:2
slow pointer at 2, fast pointer at 4
Iteration:3
slow pointer at 3, fast pointer at 5
STOP!

This is working because the number of nodes which were left (x) after fast pointer traversed till nth node are the number of nodes which needs to be traversed 
from starting to reach xth node.

Time complexity - O(n)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        //calculate the nth node from front
        ListNode *fast=head,*slow=head;
        int cnt=0;
        while(1)
        {
          if(cnt>0)fast=fast->next;
          cnt++;
          if(cnt==n)break;
        }
        cnt=0;
        int flag=0;
        while(fast->next != NULL)
        {
            fast=fast->next;
            if(cnt>0)slow=slow->next;
            cnt++;
            flag=1;
        }
        if(flag==0)return head->next;
        slow->next=slow->next->next;
        return head;
    }
};

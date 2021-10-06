/*
Problem link - https://leetcode.com/problems/reverse-linked-list/submissions/
Time complexity -O(n)
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
class Solution 
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if(head==NULL)return head;
        ListNode* dummy=NULL;
        ListNode* adj;
        
        adj=head->next; //adj is pointing to next of head
        while(1)
        {
          head->next=dummy;
          dummy=head;
          if(adj==NULL)break;
          head=adj;
          adj=adj->next;
        }
        
        return head;
    }
};

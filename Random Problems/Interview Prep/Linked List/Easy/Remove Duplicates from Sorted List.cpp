//https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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

/*
TC - O(N)
SC - O(1)
*/
class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
      if(head==NULL)return head;
      ListNode* trav=head;
      while(trav->next!=NULL)
      {
        if(trav->val == trav->next->val)
        {
            trav->next=trav->next->next;
        }
        else
        {
            trav=trav->next;
        }
      }
      return head;
    }
};

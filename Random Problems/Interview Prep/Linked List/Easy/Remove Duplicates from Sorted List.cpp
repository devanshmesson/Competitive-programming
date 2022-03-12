//https://leetcode.com/problems/remove-duplicates-from-sorted-list/
/*
Approach 1 (Iterative)
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
        if(trav->val == trav->next->val)trav->next=trav->next->next;
        else trav=trav->next;   
      }
      return head;
    }
};

/*
Approach 2 - Recursive
TC - O(N)
SC - O(N)
*/
class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
      if(head==NULL)return head;
      ListNode* returning_node=deleteDuplicates(head->next);
      if(returning_node==NULL){head->next=returning_node;return head;}
      if(returning_node->val==head->val)return returning_node;
      else
      {
          head->next=returning_node;
          return head;
      }
    }
};

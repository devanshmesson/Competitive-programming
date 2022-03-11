//https://leetcode.com/problems/remove-linked-list-elements/

//Approach 1
class Solution 
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
      if(head==NULL)return head;
      ListNode *tail=NULL, *newhead=NULL;
      ListNode *cur=head;
      int flag=0;
      while(cur!=NULL)
      {
          if(cur->val!=val)
          { 
            if(flag==0){tail=cur; newhead=tail; flag=1;} 
            else 
            {
                tail->next=cur;
                tail=tail->next;
            }
          }
          cur=cur->next;
      }
     if(tail!=NULL)tail->next=NULL;
     return newhead;
    
        
    }
};

//Approach 2.1
class Solution 
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
      if(head==NULL)return head;
      ListNode *dummy=new ListNode();
      dummy->next=head;
      // while(head!=NULL && head->val==val)head=head->next;
      ListNode *cur=dummy;
      while(cur!=NULL && cur->next!=NULL)
      {
          if(cur->next->val==val)
          {
              cur->next=cur->next->next;
          }
          else cur=cur->next;
      }
      return dummy->next;
        
    }
};

//Approach 2.2
class Solution 
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
      if(head==NULL)return head;
      while(head!=NULL && head->val==val)head=head->next;
      ListNode *cur=head;
      while(cur!=NULL && cur->next!=NULL)
      {
          if(cur->next->val==val)
          {
              cur->next=cur->next->next;
          }
          else cur=cur->next;
      }
      return head;
        
    }
};


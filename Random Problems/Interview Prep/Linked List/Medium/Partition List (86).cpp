//https://leetcode.com/problems/partition-list/
class Solution 
{
public:
    ListNode* partition(ListNode* head, int x) 
    {
        if(head==NULL || head->next==NULL)return head;
        ListNode *head1=NULL,*tail1=NULL, *head2=NULL,*tail2=NULL, *cur=head;
        int flag1=0,flag2=0;
    
        while(cur!=NULL)
        {
          if(cur->val<x)
          {
            if(flag1==0){head1=cur;tail1=cur;flag1=1;}
            else {tail1->next=cur; tail1=tail1->next;}
          } 
          else
          {
            if(flag2==0){head2=cur;tail2=cur;flag2=1;}
            else {tail2->next=cur; tail2=tail2->next;}
          }
          cur=cur->next;
        }
        if(tail2!=NULL)tail2->next=NULL;
        if(tail1!=NULL){tail1->next=head2; return head1;}
        return head2;    
    }
};

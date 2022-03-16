//https://leetcode.com/problems/reverse-nodes-in-k-group/
class Solution 
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==NULL || head->next==NULL || k==1)return head;
        ListNode* pre=new ListNode(),*cur=head;
        ListNode* save=pre;
        pre->next=head;
        int len=0;
        while(cur!=NULL){cur=cur->next;len++;}
        int stop=len-(len%k)+1;
        ListNode *last=pre->next, *nextnode=pre->next->next->next;
        cur=pre->next->next;
        int pos=2;
        while(pos<stop)
        {
            last->next=cur->next;
            cur->next=pre->next;
            pre->next=cur;
            
            if(pos%k==0)
            {
              pre=last;
              if(last)last=last->next;
              if(last)cur=last->next;
              if(cur)nextnode=cur->next;
              pos+=2;
            }
            else
            {
             //for next iteration
             cur=nextnode;
             if(nextnode!=NULL)nextnode=nextnode->next;
             pos++; 
            }
        }
        return save->next;
    }
};

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
        ListNode *last=pre;
        int pos=0;
        while(len>=k)
        {
            last=last->next;
            cur=last->next;
            for(int i=1;i<k;i++)
            {
              last->next=cur->next;
              cur->next=pre->next;
              pre->next=cur;
              cur=last->next;
            } 
            pre=last;
            len-=k;
        }
        return save->next;
    }
};

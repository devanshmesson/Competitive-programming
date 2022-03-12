//https://leetcode.com/problems/swap-nodes-in-pairs/

//Approach - 1 (iterative)
class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)return head;
        ListNode *prev=head, *cur=head->next;
        ListNode* save=NULL;
        //head->next will be returned at the end
        head=head->next;
        while(prev!=NULL && cur!=NULL)
        {
          //swap adjacent nodes
          prev->next=prev->next->next;
          cur->next=prev;
          //connect prev of previous iteration to cur node
          if(save!=NULL)save->next=cur;
          //save is pointing to prev node for next iteration
          save=prev;
            
          //move to next two adjacent nodes
          prev=prev->next;
          if(prev!=NULL)cur=prev->next;
        }
        return head;
        
    }
};

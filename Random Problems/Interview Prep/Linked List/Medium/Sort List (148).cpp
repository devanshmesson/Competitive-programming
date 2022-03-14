//https://leetcode.com/problems/sort-list/
class Solution 
{
public:
    ListNode* merge2list(ListNode* head1, ListNode* head2)
    {
        ListNode* tail=new ListNode();
        ListNode* head=tail;
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->val < head2->val)
            {
              tail->next=head1;
              tail=tail->next;
              head1=head1->next;
            }
            else
            {
                tail->next=head2;
                tail=tail->next;
                head2=head2->next;
            }
        }
        while(head1!=NULL){tail->next=head1; tail=tail->next;  head1=head1->next;}
        while(head2!=NULL){tail->next=head2; tail=tail->next;  head2=head2->next;}
        return head->next;
    }
    ListNode* sortList(ListNode* head) 
    {
       if(head==NULL || head->next==NULL)return head;
       //Calculating middle of linked list
       ListNode *slow=head, *fast=head, *head2;
       while(fast->next!=NULL && fast->next->next!=NULL)
       {
          slow=slow->next;
          fast=fast->next->next;
       }
       //Saving the head of second half
       head2=slow->next;
       //Breaking the 2 halves by point mid to NULL
       slow->next=NULL;
       //Recursively calling first half to get sorted
       ListNode *sorted1=sortList(head);
       //Recursively calling second half to get sorted
       ListNode *sorted2=sortList(head2);
       //Merging 2 sorted lists
       return merge2list(sorted1, sorted2);
    }
};

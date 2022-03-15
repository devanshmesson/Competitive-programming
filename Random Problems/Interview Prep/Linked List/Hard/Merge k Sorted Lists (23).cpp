//https://leetcode.com/problems/merge-k-sorted-lists/
/*
Approch 1
TC - O(N*K)
SC - O(1)
*/
ListNode* merge2list(ListNode *head1, *head2)
{
  ListNode* tail=new ListNode();
  ListNode* head=tail;
  while(head1!=NULL && head2!=NULL)
  {
    if(head1->val < head2->val)
    {
      tail->next=head1;
      head1=head1->next;
    }
    else
    {
      tail->next=head2;
      head2=head2->next;
    }
    tail=tail->next;
  }
  while(head1!=NULL){tail->next=head1; tail=tail->next; head1=head1->next;}
  while(head2!=NULL){tail->next=head2; tail=tail->next; head2=head2->next;}
  return head->next;
}


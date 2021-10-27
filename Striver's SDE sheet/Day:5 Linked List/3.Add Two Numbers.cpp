/*
Link - https://leetcode.com/problems/add-two-numbers/
Solution:
1.Traverse the two list simultaneously, add digits, store their carries.
2.Traverse till the two lists and the carry is non-zero.
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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
      ListNode *start=NULL,*cur=NULL,*prev=NULL;
      int carry=0,digit;
      while(l1!=NULL || l2!=NULL || carry > 0)
      {
          int a=0,b=0;
          if(l1!=NULL){a=l1->val;l1=l1->next;}
          if(l2!=NULL){b=l2->val;l2=l2->next;}
          int sum= a+b+carry;
          carry=0,digit=0;
          digit = sum%10;
          sum/=10;
          carry=sum%10;
          cur=new ListNode(digit);
          if(start==NULL){start=cur;prev=start;continue;}
          prev->next = cur;
          prev=cur;
      }
        return start;
    }
};

/*
Link - https://leetcode.com/problems/merge-two-sorted-lists/
Solution:1 
1.Perform merge operation of merge sort algorithm.
2.Make a new linked list and add the elements.

Time complexity - O(n1+n2)
Space complexity - O(n1+n2)

Solution:2
1.Perform merge operation of merge sort algorithm.
2.Dont make a new list, just connect the selected elements with links.
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
class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
       ListNode* prev=NULL,*ans=NULL;
       int flag=0;
       if(l1==NULL)return l2;
       if(l2==NULL)return l1;
       while(l1!=NULL && l2!=NULL)
       { 
           if(l1->val < l2->val)
           {
               if(prev==NULL)prev=l1;
               else 
               {
                   prev->next=l1;
                   prev=prev->next;
               }
               l1=l1->next;
           }
           else 
           {
               if(prev==NULL)prev=l2;
               else 
               {
                   prev->next=l2; 
                   prev=prev->next;
               }
               l2=l2->next;
           }
           if(flag==0){ans=prev; flag=1;}
       } 
     while(l1!=NULL)
     {
        prev->next=l1; 
        prev=prev->next;
        l1=l1->next;
     }
     while(l2!=NULL)
     {
        prev->next=l2; 
        prev=prev->next;
        l2=l2->next;
     }
     return ans;
    }
};

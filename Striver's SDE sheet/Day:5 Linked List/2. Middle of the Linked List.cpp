//Problem Link - https://leetcode.com/problems/middle-of-the-linked-list/

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

//Time complexity- O(n)+O(n/2)
class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* temp=head;
        int cnt=1;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            cnt++;
        }
        cnt=cnt/2;
        cnt++;
        int stop=1;

        while(stop<cnt)
        {
            stop++;
            head=head->next;
        }
        return head;
    }
};

//-----------------------------------------------------------------
//Time complexity  - O(n/2)
class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(1)
        {
            if(fast->next==NULL)break;
            if(fast->next->next==NULL){slow=slow->next;break;}
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
};

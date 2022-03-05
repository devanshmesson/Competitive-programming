//Approach -1 
//Used Hashing 
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        map<ListNode*,int>mp;
        int ok=0;
        if(head==NULL)return false;
        while(head->next!=NULL)
        {
            if(mp[head]>0){ok=1;break;}
            mp[head]++;
            head=head->next;
        }
        
        if(ok==1)return true;
        else return false;
        
    }
};

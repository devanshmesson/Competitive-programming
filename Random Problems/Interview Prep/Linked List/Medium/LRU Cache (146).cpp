//https://leetcode.com/problems/lru-cache/
class LRUCache 
{
public:
    struct node
    {
      // public:
      int key;
      int val;
      node *next;
      node *prev;
      node(int key1,int value)
      {
         key=key1;
         val=value;
         next=NULL;
         prev=NULL;
      }
    };
    
    node *head= new node(1,1);
    node *tail=new node(1,1);
    
    int cap;
    unordered_map<int, node*>address;
    
    LRUCache(int capacity) 
    {
      cap=capacity;
      head->next=tail;
      tail->prev=head;
    }
    
    int get(int key) 
    {
      if(address.find(key)!=address.end())
      {
           node* oldnode=address[key];
           //Removing the node from doubly linked list
            oldnode->prev->next=oldnode->next;
            oldnode->next->prev=oldnode->prev;

            //Adding after the head
            oldnode->next=head->next;
            head->next->prev=oldnode;
            head->next=oldnode;
            oldnode->prev=head;  
            return address[key]->val;
      }
      return -1;
    }
    
    void put(int key, int value) 
    {
      int size=address.size();
      if(address.find(key)!=address.end())
      { 
         node* oldnode=address[key];
         //Updating the value of the node
         oldnode->val=value;

         if(head->next!=oldnode)
         {
            //Removing the node from doubly linked list
            oldnode->prev->next=oldnode->next;
            oldnode->next->prev=oldnode->prev;

            //Adding after the head
            oldnode->next=head->next;
            head->next->prev=oldnode;
            head->next=oldnode;
            oldnode->prev=head;  
         }   
      }
      else if(size<cap)
      {
        node *newnode=new node(key,value);
        //Adding after the head
        newnode->next=head->next;
        head->next->prev=newnode;
        head->next=newnode;
        newnode->prev=head;
        //Saving the address of key.
        address[key]=newnode;
      }
      else if(size==cap)
      {
         
         //Removing the Least recently used key (tail's previous)
         node* lru=tail->prev;
         address.erase(lru->key);
         lru->prev->next=lru->next;
         lru->next->prev=lru->prev;
         node* newnode=new node(key, value);
         //Adding after the head
         newnode->next=head->next;
         head->next->prev=newnode;
         head->next=newnode;
         newnode->prev=head;
         address[key]=newnode;
         
      }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//https://leetcode.com/problems/lfu-cache/
class LFUCache
{
public:
    struct node
    {
        int val, key,used;
        node* next;
        node* prev;
        node(int key_, int val_)
        {
         used=0;
         key=key_;
         val=val_;
         next=NULL;
         prev=NULL;
        }
    };
    int cap;
    //min use counter stores the minimum use counter among all the use counters
    int min_use_counter=1;
    //Representation of this map is {use_counter,head->key1->key2->tail}
    unordered_map<int,pair<node*,node*>>cnt;
    //Stores address of the node which contains key-value pair
    unordered_map<int, node*>address;
    
    //Initialize a list of keys whose use-counter is count
    void initialize_list(int count)
    {
      cnt[count].first=new node(1,1);
      cnt[count].second=new node(1,1);
      cnt[count].first->next=cnt[count].second;
      cnt[count].second->prev=cnt[count].first;
    }
    //remove node in the doubly linked list
    void removenode(node *oldnode)
    {
     oldnode->prev->next=oldnode->next;
     oldnode->next->prev=oldnode->prev;
    }
    //add node after the head of doubly linked list of keys having use-counter as count
    void addnode(node *newnode, int count)
    {
      node *head=new node(1,1);
      head=cnt[count].first;
      newnode->next=head->next;
      head->next->prev=newnode;
      head->next=newnode;
      newnode->prev=head;
    }
    //Update use-counter of key which is requested in put() or get()
    void update_key_usecounter(int key)
    {
       int count=address[key]->used;
       //Update use counter of key in the node
       address[key]->used+=1;
       //Initialize the list if this is the first key to have use-counter=count+1
       if(cnt[count+1].first==NULL)initialize_list(count+1);
       //Add this node after the head of the list of use counter=count+1
       addnode(address[key], count+1);
       //if this is not an existing node, then minimum use counter becomes 1
       //Else if a list is going to be empty, that means the last node which was removed has gone to list of use-                        counter=count+1
       if(count==0)min_use_counter=1;
       else if(cnt[min_use_counter].first->next->next==NULL)min_use_counter++;
    }
    LFUCache(int capacity){cap=capacity;}
    int get(int key) 
    {
      if(address.find(key)!=address.end() && cap>0)
      {
        removenode(address[key]);
        update_key_usecounter(key);
        return address[key]->val;
      }
      return -1;
    }
    void put(int key, int value) 
    { 
      if(cap==0)return;
      int size=address.size();
      node* resnode;
      if(address.find(key)!=address.end())
      {
          resnode=address[key];
          resnode->val=value;
          removenode(address[key]);
      }
      else if(size<cap)resnode=new node(key,value);
      else if(size==cap)
      {
        //If size of the list is 1, then tails->prev will be LFU
        //If size of the list is >1, then tails->prev will be LRU 
        resnode=new node(key,value);
        address.erase(cnt[min_use_counter].second->prev->key); 
        removenode(cnt[min_use_counter].second->prev);  
      } 
      address[key]=resnode;
      update_key_usecounter(key);
    } 
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node* next;
}*head;

int addnode(int data)
{
  Node* new_node=new Node;
  new_node->data=data;
  new_node->next=head;
  head=new_node;
}
int search(int ele)
{
  Node* current=head;
  while(current!=NULL)
  {
    if(current->data==ele){cout<<"found"<<endl;break;}
    current=current->next;
  }
}
int main()
{
  int a[5];
  for(int i=0;i<5;i++){cin>>a[i]; addnode(a[i]);}
  search(12);
}

#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node* next;
};
node* create_node(int val){
	node* temp = new node();
	temp->data=val;
	temp->next=NULL;
return temp;
}
void print(node* head){
	node* ptr=head;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
}
//Inserting at begining
node* insert_at_beg(node* head){
	cout<<"Enter the value"<<'\n';
	int val;cin>>val;
	node* temp = create_node(val);
	temp->next=head;
	head=temp;
return head;
}
//Inserting at end
node* insert_at_end(node* head){
	cout<<"Enter the value"<<'\n';
	int val;cin>>val;
	node* temp = create_node(val);
	node* ptr=head;
	while(ptr->next!=NULL){
       ptr = ptr->next;
	}
	ptr->next=temp;
return head;
}
//Insert after specific Index
node* insert_at_pos(node* head){
    cout<<" Enter the pos and value"<<'\n';
    int pos,val;
    cin>>pos>>val;
    node* temp = create_node(val);
    node* ptr1 = head;
    node* ptr2 = head->next;
    for(int i=0;i<pos;i++){
    	ptr1 = ptr1->next;
    	ptr2 = ptr2->next;
    }
    temp->next = ptr2;
    	ptr1->next=temp;
  return head;

}
int main(){
	int n;cin>>n;
    node* head=NULL;
    node* ptr;
    for(int i=0;i<n;i++){
    	int val;cin>>val;
    	node* temp = create_node(val);
    	if(head==NULL){
    		head=temp;
    		ptr=head;
    	}else{
    		ptr->next=temp;
    		ptr=ptr->next;
    	}
    }
   print(head);
    cout<<"Enter the number of query"<<'\n';
    int query;cin>>query;
   cout<<"press 1 to insert at begining"<<'\n';
   cout<<"press 2 to insert at end"<<'\n';
   cout<<" press 3 to insert at specific position"<<'\n';
    while(query--){
    	int k;cin>>k;
    	if(k==1){
    		head = insert_at_beg(head);
    	}else if(k==2){
    		head = insert_at_end(head);
    	}else if(k==3){
    		head = insert_at_pos(head);
    	}else{
    		cout<<"Invalid Input"<<'\n';
    	}
    }
  print(head);
 return 0;
}
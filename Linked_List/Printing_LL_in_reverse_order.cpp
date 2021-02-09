#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node* next;
};

void print_reverse(node* head){
	node* ptr = head;
	node* prev =head;
	while(ptr->next!=NULL)
		ptr = ptr->next;

	while(ptr!=head){
		while(prev->next!=ptr){
			prev = prev->next;
		}
		cout<<ptr->data<<" ";
		ptr=prev;
		prev=head;
	}
	if(ptr==head)
		cout<<ptr->data<<'\n';
}

node* create_node(int val){
	node* temp = new node();
	temp->data=val;
	temp->next=NULL;
	return temp;
}
int main(){
	int n;cin>>n;
	node* head=NULL;
	node*ptr=NULL;
	for(int i=0;i<n;i++){
		int val;cin>>val;
        node* temp = create_node(val);
        if(head==NULL){
        	head=temp;
        	ptr=head;
        }else{
        	ptr->next=temp;
        	ptr = ptr->next;
        }
	}
	print_reverse(head);
return 0;
}
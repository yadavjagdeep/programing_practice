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
/****************************************/
node* merge(node* h1,node* h2){
	node*head=NULL;
	if(h1->data <= h2->data)
		head=h1;
	else
		head=h2;

	while(h1!=NULL && h2!=NULL){
		if(h1->data <= h2->data){
			while(h1->next!=NULL && h1->next->data <= h2->data){
				h1 = h1->next;
			}
			node*temp=h1;
			h1=h1->next;
			temp->next=h2;
		}
		else if(h2->data <= h1->data){
			while(h2->next!=NULL && h2->next->data <= h1->data){
				h2=h2->next;
			}
			node *temp=h2;
			h2=h2->next;
			temp->next=h1;
		}
	}
return head;
}

/******************************************/

int main(){
	int n,m;cin>>n>>m;
	node* h1=NULL,*h2=NULL,*ptr;
	for(int i=0;i<n;i++){
        int val;cin>>val;
        node* temp = create_node(val);
        if(h1==NULL){
        	h1=temp;
        	ptr=temp;
        }else{
        	ptr->next=temp;
        	ptr=ptr->next;
        }
	}
  for(int i=0;i<m;i++){
        int val;cin>>val;
        node* temp = create_node(val);
        if(h2==NULL){
        	h2=temp;
        	ptr=temp;
        }else{
        	ptr->next=temp;
        	ptr=ptr->next;
        }
	}

  node*head = merge(h1,h2);
  print(head);

return 0;
}
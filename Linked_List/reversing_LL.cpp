#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node* next;
};
node* create_node(int val){
	node* temp = new node();
	temp->data = val;
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
node* reverse(node* head){
	if(head->next==NULL)
		return head;
	node* ptr1=head->next;
	node* ptr2=ptr1->next;
	head->next=NULL;
	while(ptr2!=NULL){
		ptr1->next=head;
		head = ptr1;
		ptr1=ptr2;
		ptr2 = ptr2->next;
		//cout<<head->data<<" "<<ptr1->data<<" "<<ptr2->data<<'\n';
	}
    ptr1->next=head;
    head=ptr1;
	//print(head);
	return head;
}

int main(){
	int n;cin>>n;
    node* head = NULL;
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

    head=reverse(head);
    print(head);
  return 0;
}
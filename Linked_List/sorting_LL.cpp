#include<bits/stdc++.h>
using namespace std;
class node
{
public:
	int data;
	node* next;
};
node* create_node(int val){
	node* temp = new node;
	temp->data=val;
	temp->next=NULL;
return temp;
}
void sort_LL(node* head){ //Bubble sort by swapping dataof nodes
   for(node* i=head;i->next!=NULL;i=i->next){
   	for(node* j=i;j!=NULL;j = j->next){
   		if(i->data>j->data){
   			int temp = i->data;
   			i->data=j->data;
   			j->data=temp;
   		}
   	}
   }
}
void print(node* head){
	node* ptr=head;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
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

	sort_LL(head);
	print(head);
return 0;

}
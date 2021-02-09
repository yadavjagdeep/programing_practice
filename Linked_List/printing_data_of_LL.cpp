#include<bits/stdc++.h>
using namespace std;
/*struct  node
{
	int data;
	struct node* next;
	
};*/
class node{
public:
	int data;
	node* next;
};

node* create_node(int val){
	//node * temp = (node*)malloc(sizeof(node));
	node* temp = new node();
	temp->data = val;
	temp->next=NULL;
	return temp;
}
void print(node* ptr){
	while(!ptr==NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
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

    print(head);
  
return 0;
}
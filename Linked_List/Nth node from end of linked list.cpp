#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
	node(int val){
		data=val;
		next=NULL;
	}
};

int nth_element_from_last(node *head,int n){
	node *fast=head;
	node *slow=head;
	 // => Now we will move fast pointer to n nodes
	// => then start moving both the pointers one step each
	// => when fast pointer will becomes null then slow will be pointing
	//    to the desired position

	 while(n--)
	 	fast = fast->next;
	 while(fast){
	 	slow = slow->next;
	 	fast = fast->next;
	 }
  return slow->data;
}
int main(){
    int n;cin>>n;
    node *head=NULL;
    node *ptr;
    for(int i=0;i<n;i++){
    	int val;cin>>val;
    	node *temp = new node(val);
    	if(head==NULL){
    		head =temp;
    		ptr=head;
    	}else{
    		ptr->next=temp;
    		ptr = ptr->next;
    	}
    }

    int pos;cin>>pos;
    cout<<nth_element_from_last(head,pos)<<'\n';
  return 0;
}

/*-----------> check your firefox pocket <--------------------*

  => The idea is to detect the loop using slow and fast pointer
  => Now fix one of them at their meeting point
  => make the second one equals to head
  => Now move both the pointer one step forword untill they meet
  => The meeting point of these pointers is the starting point of loop
*/

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

int start_of_loop(node *head){
	node *slow = head;
	node *fast = head;
	while(fast!=NULL && fast->next!=NULL && slow!=NULL){
      fast = fast->next->next;
      slow = slow->next;
      if(slow == fast)
      	break;
	}
	if(fast==NULL && slow == NULL)
		return -1;

	fast=head;
	while(slow!=fast){
		slow = slow->next;
		fast = fast->next;
	}
return slow->data;
}
int main(){
    int n;cin>>n;
    node *head=NULL;
    node *ptr;
    node *loop;
    for(int i=0;i<n;i++){
    	int val;cin>>val;
    	node *temp = new node(val);
    	if(i==2)
    		loop =temp;

    	if(head==NULL){
    		head =temp;
    		ptr=head;
    	}else{
    		ptr->next=temp;
    		ptr = ptr->next;
    	}
    }
   ptr->next=loop;
   cout<<start_of_loop(head)<<'\n';

return 0;
}
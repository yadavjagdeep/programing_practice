/*
  => We have to check if given LL is Palindrom in O(n) time and O(1)space
  => The idea is to reverse the LL from mid and then compare
  => For reversing LL we use concept of slow and fast pointer
     when fast reaches end slow will we pointing to mid
  => The approch will consist of huge number of edge cases
  => so handle them properly to prevent segmentation fast

  =>-------> Happy Coding <=> Happy Debugging <--------<=
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
void print(node* head){
    node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
bool is_palindrom(node *head){

   /* Edge cases*/
    if(head->next==NULL)
        return true;
    else if(head->next->next == NULL && head->data == head->next->data)
        return true;
    else if(head->next->next == NULL && head->data != head->next->data)
          return false;
    node *fast = head;
    node *slow = head;
    int cnt=0;
    while(fast && fast->next && slow){
        fast = fast->next->next;
        slow = slow->next;
    }
    node *p=head;
    while(p){
        cnt++;
        p = p->next;
    }

    if(cnt%2!=0)
        slow = slow->next;

    node *last=head;
    while(last->next!=slow)
        last  =last->next;

    if(cnt==3 && head->data == slow->data)
        return true;
    else if(cnt==3 && head->data != slow->data)
        return false;

    node *ptr1 = slow->next;
    node *ptr2 = ptr1->next;
    slow->next =NULL;
    while(ptr2){
        ptr1->next = slow;
        slow = ptr1;
        ptr1 = ptr2;
        ptr2 =ptr2->next;
    }
    ptr1->next = slow;
    slow = ptr1;
    last->next =ptr1;
   
   bool flag=true;
   ptr1 = head;
   ptr2 = last->next;

  for(int i=0;i<cnt/2;i++){
    if(ptr1->data != ptr2->data)
        flag = false;

    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

   if(flag)
    return true;
return false;
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
    /*head = is_palindrom(head);
    print(head);*/
    if(is_palindrom(head))
        cout<<"Palindrom"<<'\n';
    else
        cout<<"Not Palindrom"<<'\n';
return 0;
}
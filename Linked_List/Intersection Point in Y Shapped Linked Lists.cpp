//=> common node have value 4 <=

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
/*
class node{
public:
	int data;
	node *data;
};*/

// => This is a brute force approch and will take O(n*m) 

/*int point_of_intersection(node *head1,node *head2){
	node *ptr2 =head2;
   while(ptr2!=NULL){
      node *ptr1 = head1;
      while(ptr1!=NULL){
      	if(ptr1==ptr2)
      		return ptr1->data;

      	ptr1 = ptr1->next;
      }
      ptr2 = ptr2->next;
   }
return -1;
}*/
// => An better approch to solve it is traverse one list and multiply all
//    elements of list by -1
// => Now traverse the second list when we encounter a -ve value return -ve(val)
int point_of_intersection(node *head1,node *head2){
	node *ptr1 = head1;
	while(ptr1!=NULL){
		ptr1->data = (-1*ptr1->data+1); // extra 1 is added to takle case of 0
		ptr1 = ptr1->next;
	}
	node *ptr2=head2;
	while(ptr2!=NULL){
		if(ptr2->data < 0)
			return -1*(ptr2->data)-1;

		ptr2 = ptr2->next;
	}
return -1;
}
int main(){
    int n;cin>>n;
    node *head1 = NULL;
    node *ptr;
    node *commom = new node(4);
    for(int i=0;i<n;i++){
    	if(i==3){
    		ptr->next = commom;
    		ptr = ptr->next;
    	}else{
    		int val;cin>>val;
    	node *temp = new node(val);
    	if(head1 == NULL){
          head1=temp;
          ptr=head1;
    	}else{
    		ptr->next=temp;
    		ptr = ptr->next;
    	}
    	}
    	
    }
  
     node *head2 = NULL;
     for (int i = 0; i < n; ++i)
     {
     	if(i==4){
     		ptr->next = commom;
     		ptr = ptr->next;
     	}else{
     		int val;cin>>val;
     		node *temp = new node(val);
     		if(head2==NULL){
               head2 = temp;
               ptr=head2;
     		}else{
     			ptr->next = temp;
     			ptr = ptr->next;
     		}
     	}
     }

     cout<<point_of_intersection(head1,head2)<<'\n';

return 0;
}
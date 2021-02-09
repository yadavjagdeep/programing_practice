#include<iostream>
#include<vector>
using namespace std;
typedef struct node{
  int data;
  struct node* next;
}node;
node* create_node(int val){
  node* temp = (node*)malloc(sizeof(node));
  temp->data = val;
  temp->next = NULL;
  return temp;
}
int main(){
  int n1,n2;
  node* head1=NULL;
  node* head2=NULL;
  cout<<"Enter no of elements in list1"<<endl;
  cin>>n1;
  int x;cin>>x;
  head1 = create_node(x);
  node* temp = head1;
  for(int i=0;i<n1;i++){
    int val;cin>>val;
    temp->next = create_node(val);
    temp = temp->next;
  }
  while (head1->next!=NULL) {
    cout<<head1->data<<" ";
    head1 = head1->next;
  }
return 0;
}

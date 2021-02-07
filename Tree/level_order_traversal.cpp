#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node *left;
	node *right;
	node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};
//=> creating BST
node *insert_BST(node *root,int val){
	if(root == NULL)
		return new node(val);
	else if(val <= root->data)
	   root->left = insert_BST(root->left,val);
	 else
		root->right = insert_BST(root->right,val);
return root;
}

//=> Level order traversal
void level_order(node *root){
	queue<node*>q;
	q.push(root);

	while(!q.empty()){
     node *temp = q.front();
     cout<<temp->data<<" ";
     if(temp->left!= NULL)
     	q.push(temp->left);
     if(temp->right != NULL)
        q.push(temp->right);

     q.pop();
	}
}
int main(){
  int n;cin>>n;
  node *root = NULL;
  while(n--){
    int val;cin>>val;
    root = insert_BST(root,val);
  }
  level_order(root);
return 0;
}
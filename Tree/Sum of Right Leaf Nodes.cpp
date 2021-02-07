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
node *BST(node *root,int val){
	if(root == NULL)
		return new node(val);
	else if(val <= root->data)
		root->left = BST(root->left,val);
	else
		root->right = BST(root->right,val);
return root;
}
void right_leaf_sum(node *root,int &sum){
	if(root->right != NULL){
		if((root->right->left == NULL) && (root->right->right == NULL)){
			sum+=root->right->data;
		}
	}
	if(root->left != NULL)
		right_leaf_sum(root->left,sum);
	if(root->right != NULL)
		right_leaf_sum(root->right,sum);
}


int main(){
	int n;cin>>n;
	node *root = NULL;
	while(n--){
		int val;cin>>val;
		root = BST(root,val);
	}
	int sum=0;
   right_leaf_sum(root,sum);
   cout<<sum<<'\n';
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
class node
{
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
int cnt=0;
node *BST(node *root,int val){
	if(root == NULL)
		return new node(val);
	else if(val <= root->data)
		root->left = BST(root->left,val);
	else
		root->right = BST(root->right,val);
return root;
}
// Intutaion behind counting leaves 
// A node is leaf if its right and left child are NULL
// Traverse whole tree and count all such node in a global variable
void count_leaves(node *root){
	if(root->left == NULL && root->right == NULL){
		cnt++;
		return;
	}
	if(root->left != NULL)
	count_leaves(root->left);
    if(root->right != NULL)
	count_leaves(root->right);
}
int main(){
	int n;cin>>n;
	node *root = NULL;
	while(n--){
		int val;cin>>val;
		root = BST(root,val);
	}
	count_leaves(root);
	cout<<cnt<<'\n';
return 0;
}
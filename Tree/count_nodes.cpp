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
// => The intution behind counting node is total number of nodes
//    is equals to nodes in left subtree + nodes in right subtree
//    + 1 for root
int count_nodes(node *root){
	if(root == NULL)
		return 0;
	return 1+(count_nodes(root->left)+count_nodes(root->right));
}
int main(){
	int n;cin>>n;
	node *root = NULL;
	while(n--){
		int val;cin>>val;
		root = BST(root,val);
	}
	cout<<count_nodes(root)<<'\n';
return 0;
}
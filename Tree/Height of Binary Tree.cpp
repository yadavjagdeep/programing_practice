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
//=> Creating Binary search tree 
node *BST(node *root,int val){
	if(root == NULL)
		return new node(val);
	else if(val <= root->data)
		root->left = BST(root->left,val);
	else
		root->right = BST(root->right,val);
return root;
}
// => Hight of binary tree
int hight(node *root){
	if(root == NULL)
		return 0;
	return 1+max(hight(root->left),hight(root->right));
}
int main(){
	int n;cin>>n;
	node *root = NULL;
	while(n--){
		int val;cin>>val;
		root = BST(root,val);
	}
	cout<<hight(root)<<'\n';
return 0;
	
}
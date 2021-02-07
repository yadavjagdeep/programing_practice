/*
  --> Finding Diameter of a binary tree is simple if we know how to find hight of a tree
  --> There can be three cases 
  1) Diameter may be present in the left subtree
  2) Diameter may be prestent in the right subtree
  3) Diameter may pass through root

   ==> when Diameter is passing through root then,
     diameter = 1+(height of left subtree + hight of right subtree) 
*/

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
// => creating Binary search tree
node* BST(node *root,int val){
	if(root == NULL)
		return new node(val);
	else if(val<= root->data)
		root->left = BST(root->left,val);
	else
		root->right = BST(root->right,val);
return root;
}
// => hight of binary Tree
int hight(node *root){
	if(root == NULL)
		return 0;
	return 1+max(hight(root->left),hight(root->right));
}
int diameter(node *root){
	if(root == NULL)
		return 0;
	int dia1 = 1+hight(root->left)+hight(root->right);
	int dia2 = diameter(root->left);
	int dia3 = diameter(root->right);
	return max({dia1,dia2,dia3});
}
int main(){
	int n;cin>>n;
	node *root = NULL;
	while(n--){
		int val;cin>>val;
		root = BST(root,val);
	}
	cout<<diameter(root)<<'\n';
return 0;
}
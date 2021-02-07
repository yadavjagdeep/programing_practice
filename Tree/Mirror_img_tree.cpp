// --> Inorder traversal of a BST will give output in accending order
// --> Inorder traversal of mirror image of BST give rev-accending output

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
// Binary search tree
node *BST(node *root,int val){
	if(root == NULL)
		return new node(val);
	else if(val <= root->data)
		root->left = BST(root->left,val);
	else
		root->right = BST(root->right,val);
return root;
}
// => Inorder Traversal of a BST gives data in sorted order
// Inorder traversal
void inorder(node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
// => To create mirror image of a tree we are needed to swap left and right child
void mirror_BST(node *root){
	if(root == NULL)
		return;
	node *temp = root->left;
	root->left = root->right;
	root->right = temp;

	mirror_BST(root->left);
	mirror_BST(root->right);
}
int main(){
	int n;cin>>n;
	node *root = NULL;
	while(n--){
     int val;cin>>val;
     root = BST(root,val);
	}
  inorder(root);
  cout<<'\n';
  mirror_BST(root);
  inorder(root);
 return 0;
}
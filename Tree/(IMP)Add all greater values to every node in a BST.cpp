/*
  --> A good question if to be done in O(n) time and O(h) space
  By using the property of BST we can canclude that the right most
  element will be highest and only 0 can be added to it

  The left most element is min and so all nodes value should be added to it
  By using the same property we first move to right add req sum to it
  intially sum = 0; and then make sum = updated value of that node
  now we move to left of it and do the same

    => Magic of recursion will take care of rest <=
*/

#include <bits/stdc++.h>
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
void modify(node *root,int &sum){
	if(root == NULL)
		return;
	modify(root->right,sum);
	root->data = root->data+sum;
	sum=root->data;
	modify(root->left,sum);

}
void inorder(node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main(){
	int n;cin>>n;
	node *root = NULL;
	while(n--){
		int val;cin>>val;
		root = BST(root,val);
	}
	int sum=0;
	//inorder(root);
	modify(root,sum);
	inorder(root);
return 0;
}
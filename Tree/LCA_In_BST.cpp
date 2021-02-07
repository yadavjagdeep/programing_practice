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

// => Recursive code to create Binary Search tree
node *BST(node *root,int val){
	if(root == NULL)
		return new node(val);
	else if(val <= root->data)
		root->left = BST(root->left,val);
	else
		root->right = BST(root->right,val);
return root;
}
// Intution behind finding LCA in BST is:
// => the first element which is greater/equal to n and less/equal to m
//     is LCA of n and m 
int LCA_BST(node *root,int n,int m){
    if(root == NULL)
    	return 0;
     if (root->data > n && root->data > m) 
        return LCA_BST(root->left, n, m); 
    if (root->data < n && root->data < m) 
        return LCA_BST(root->right, n, m); 
   
  return root->data;
}
int main(){
	int k;cin>>k;
	node *root = NULL;
	while(k--){
		int val;cin>>val;
		root = BST(root,val);
	}
	int n,m;cin>>n>>m;
	cout<<LCA_BST(root,n,m)<<'\n';
return 0;
}
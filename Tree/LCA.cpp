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
node *LCA;
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
// finding Lowest common ancestor
bool find_lca(node *root,int n,int m){
	if(root == NULL)
		return false;
	if(root->data == n || root->data == m){
		LCA = root;
		return true;
	}
	bool left = find_lca(root->left,n,m);
	bool right = find_lca(root->right,n,m);
	if(left && right){
		LCA = root;
		return false;
	}
	return (left || right);
}
int main(){
	int k;cin>>k;
	node *root = NULL;
	while(k--){
		int val;cin>>val;
		root = BST(root,val);
	}
	int n,m;
	cin>>n>>m;
  find_lca(root,n,m);
  cout<<LCA->data<<'\n';
return 0;
}
#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	int idx;
	node *left;
	node *right;
	node(int val){
		data = val;
		idx = 0;
		left = NULL;
		right = NULL;
	}
};
node *root1 = NULL;
node *BST(node *root,int val){
	if(root == NULL)
		return new node(val);
	else if(val <= root->data)
		root->left = BST(root->left,val);
	else
		root->right = BST(root->right,val);
return root;
}
void set_index(node *root){
	if(root == NULL)
		return;
	int k = root->idx;
	if(root->left != NULL){
		root->left->idx = (2*k)+1;
		set_index(root->left);
	}
	if(root->right != NULL){
		root->right->idx = (2*k)+2;
		set_index(root->right);
	}
}

void inorder(node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" "<<root->idx<<'\n';
	inorder(root->right);
}
void convert_tree_arr(node *root,std::vector<int> &v){
    if(root == NULL)
    	return ;
    v[root->idx] = root->data;
    if(root->left != NULL)
    	convert_tree_arr(root->left,v);
    if(root->right != NULL)
    	convert_tree_arr(root->right,v);
}
void arr_to_tree(int i,std::vector<int> v){

   if(v[(2*i)+1] != -1){
   	root1->left = new node(v[(2*i)+1]);
   	cout<<root1->left->data<<'\n';
   	arr_to_tree(2*i+1,v);
   }
   if(v[(2*i)+2] != -1){
   	root1->right = new node(v[(2*i)+2]);
   	cout<<root1->right->data<<'\n';
   	arr_to_tree(2*i+2,v);
   }
}

int main(){
	int n;cin>>n;
	node *root = NULL;
	while(n--){
		int val;cin>>val;
		root = BST(root,val);
	}
	set_index(root);
	//inorder(root);
	std::vector<int> v(100,-1);
	convert_tree_arr(root,v);
	root1 = new node(v[0]);
	arr_to_tree(0,v);
	inorder(root1);

return 0;
}
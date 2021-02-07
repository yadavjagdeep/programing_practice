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
//printing vetor
void print(std::vector<int> v){
	for(auto x:v)
		cout<<x<<" ";
}
// All path to leaves
void path_to_leaves(node *root,std::vector<int> &v){
	if(root->left == NULL && root->right == NULL){
		print(v);
		cout<<root->data<<'\n';
	}
	v.push_back(root->data);
	if(root->left != NULL)
		path_to_leaves(root->left,v);
	if(root->right != NULL)
		path_to_leaves(root->right,v);
	v.pop_back();

}

int main(){
      int n;cin>>n;
      node *root = NULL;
      while(n--){
      	int val;cin>>val;
      	root = BST(root,val);
      }
      std::vector<int> v;
      path_to_leaves(root,v);
 return 0;
}
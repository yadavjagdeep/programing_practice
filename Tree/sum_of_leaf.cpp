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
node *BST(node *root,int val){
	if(root == NULL)
		return new node(val);
	else if(val <= root->data)
		root->left = BST(root->left,val);
	else
		root->right = BST(root->right,val);
return root;
}
//
void sum_of_leaf(node *root,std::vector<int> &v){
	if(root->left == NULL && root->right == NULL){
		v.push_back(root->data);
		return;
	}
	if(root->left != NULL)
		sum_of_leaf(root->left,v);
	if(root->right != NULL)
		sum_of_leaf(root->right,v);
}
int main(){
	int n;cin>>n;
	node *root = NULL;
	while(n--){
		int val;cin>>val;
		root = BST(root,val);
	}
	std::vector<int> v;
	sum_of_leaf(root,v);
  int sum = accumulate(v.begin(),v.end(),0);
  cout<<sum<<'\n';
 return 0;
}
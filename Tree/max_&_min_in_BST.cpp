#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node *left;
	node *right;
	node(int val){
		data = val;
		left=NULL;
		right = NULL;
	}
};

//=> BST Implimentation
node *insert(node *root, int val){
	if(root == NULL)
		return new node(val);
	else if(val <= root->data)
		 root->left = insert(root->left,val);
	else
		root->right = insert(root->right,val);

return root;
}

//=> finding max element --> max element should be at the rightmost bottom
 int find_max(node *root){
 	if(root->right == NULL)
 		return root->data;
 	 return find_max(root->right);
 }

 //=> finding min element --> min element should be at leftmost bottom
 int find_min(node *root){
 	if(root->left == NULL)
 		return root->data;
 	return find_min(root->left);
 }
int main(){
	int n;cin>>n;
	cin.ignore();
	node *root = NULL;
	while(n--){
		int val;cin>>val;
		root = insert(root,val);
	}
	cout<<"Min element = "<<find_min(root)<<'\n';
  cout<<"Max element = "<<find_max(root)<<'\n';
  
 return 0;
}
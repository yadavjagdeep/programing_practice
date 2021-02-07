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
//Creting BST
node *BST(node *root,int val){
	if(root == NULL)
		return new node(val);
	else if(val <= root->data)
		root->left = BST(root->left,val);
	else
		root->right = BST(root->right,val);
return root;
}
// first element at each level will be its left view
void left_view(node *root){
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		int n = q.size();
		std::vector<int> v;
		for(int i=0;i<n;i++){
			node *temp = q.front();
			v.push_back(temp->data);
			if(temp->left!= NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
			q.pop();
		}
		cout<<v[0]<<'\n';
		v.clear();
	}
}
// last element at each level will be its right view
void right_view(node* root){
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		int n = q.size();
		std::vector<int> v;
		for(int i=0;i<n;i++){
			 node *temp = q.front();
			 v.push_back(temp->data);
			 q.pop();
			 if(temp->left != NULL)
			 	q.push(temp->left);
			 if(temp->right != NULL)
			 	q.push(temp->right);

		}
		cout<<v.back()<<'\n';
		v.clear();
	}
}
int main(){
	int n;cin>>n;
	node *root = NULL;
	while(n--){
		int val;cin>>val;
        root = BST(root,val);
	}
	left_view(root);
     cout<<'\n';
	right_view(root);
return 0;
}
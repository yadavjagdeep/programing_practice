#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int sum;
class node{
public:
	int data;
	node *left;
	node *right;
	node(int val){
		data = val;
		left = right = NULL;
	}
};
 void inorder(node *root){
 	if(root == NULL)
 		return;
 	inorder(root->left);
 	cout<<root->data<<" ";
 	inorder(root->right);
 }

int count_sum(node *root){
    if(root == NULL)
    	return 0;
    int l = count_sum(root->left);
    int r = count_sum(root->right);
    //cout<<l<<" "<<r<<'\n';
    if((l+r+root->data)==sum)
    	cnt++;
    return l+r+root->data;
}

int main(){
	node *root = new node(5);
	root->left = new node(-10);
	root->right = new node(3);
	root->left->left = new node(9);
	root->left->right = new node(8);
	root->right->left = new node(-4);
	root->right->right = new node(7);

	//inorder(root);
	cin>>sum;
	count_sum(root);
	cout<<cnt<<'\n';
return 0;
}
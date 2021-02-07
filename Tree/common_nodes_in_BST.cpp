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
	else if(val<=root->data)
		root->left = BST(root->left,val);
	else
		root->right = BST(root->right,val);
return root;
}
int common(node *root1,node *root2){
    if(root1 == NULL && root2 == NULL)
    	return 0;

    if(root1->data == root2->data)
    	return 1;
    return (common(root1->left,root2->left)+common(root1->right,root2->right));


}

int main(){
	 	int n;cin>>n;
	 	node *root1 = NULL;
	 	while(n--){
	 		int val;cin>>val;
	 		root1 = BST(root1,val);
	 	}
	 	int m;cin>>m;
	 	node *root2 = NULL;
	 	while(m--){
	 		int val;cin>>val;
	 		root2 = BST(root2,val);
	 	}
	 	cout<<common(root1,root2)<<'\n';
	return 0;
}
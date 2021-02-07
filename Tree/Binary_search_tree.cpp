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

// => Binary search tree Implimentation <= //
node *insert(node *root,int val){
	if(root == NULL)
		return new node(val);
	else if(val<=root->data)
		root->left = insert(root->left,val);
	else
		root->right = insert(root->right,val);

return root;
}

//=> preorder treversal
void preorder(node *root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
//=> postorder treversal
void postorder(node *root){
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
//=> Inorder treversal
void inorder(node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

// search an element in BST 

bool is_present(node *root,int val){
	if(root == NULL)
		return false;
	else if(root->data == val)
		return true;
	else if(val<=root->data)
		return is_present(root->left,val);
	else
		return is_present(root->right,val);
}
int main(){
    
    int n;cin>>n;
    node *root=NULL;
    while(n--){
      int val;cin>>val;
      root = insert(root,val);
    }
    preorder(root);
    cout<<'\n';
    postorder(root);
    cout<<'\n';
    inorder(root);
    cout<<'\n'<<"Enter number of search"<<'\n';
    int k;cin>>k;
    while(k--){
    	int val;cin>>val;
    	if(is_present(root,val))
    		cout<<"Present"<<"\n";
    	else
    		cout<<"NOT Present"<<'\n';
    }
 return 0;
}
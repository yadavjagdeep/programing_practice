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
/*void inorder(node *root,std::vector<int> &v){
	if(root == NULL)
		return;
	inorder(root->left,v);
	v.push_back(root->data);
	inorder(root->right,v);
}
bool is_identical(std::vector<int> v1,std::vector<int> v2){
  if(v1.size()!=v2.size())
  	return false;
  for(int i=0;i<v1.size();i++){
  	if(v1[i]!=v2[i])
  		return false;
  }
 return true;
}*/
// Another approch from gfg
bool is_identical(node * root1,node *root2){
	if(root1 == NULL && root2 == NULL)
		return true;
	else if(root1== NULL || root2 == NULL)
		return false;
	return  (root1->data == root2->data) && is_identical(root1->left,root2->left) && is_identical(root1->right,root2->right);
}


int main(){
	int n;cin>>n;
	node *root1 = NULL;
    node *root2 = NULL;
	while(n--){
		int val;cin>>val;
		root1 = BST(root1,val);
	}
	int m;cin>>m;
	while(m--){
		int val;cin>>val;
		root2 = BST(root2,val);
	}
	/*std::vector<int> v1;
	std::vector<int> v2;
	inorder(root1,v1);
	inorder(root2,v2);
	cout<<is_identical(v1,v2)<<'\n';*/
	cout<<is_identical(root1,root2)<<'\n';
return 0;
}
 // ==> Check if tree is foldable <==
/*
  There can we multiple ways to approch this problem
   1). To change one of subtree to it's mirror and compare it with the other subtree
   2). One approch is to check is left subtree is mirror of right subtree
   3). One approch can also be od approaching is by level order traversal
*/
#include<bits/stdc++.h>
using namespace std;
class node{
public:
   int data;
   node *left;
   node *right;
   node(int val){
   	data = val;
   	left=right=NULL;
   }   
};

void mirror(node *root){
	if(root == NULL)
		return;
	node *temp = root->left;
	root->left = root->right;
	root->right = temp;
    
    mirror(root->left);
    mirror(root->right);
}

bool is_mirror(node *r1,node *r2){
	if(r1 == NULL && r2 == NULL)
		return true;
	if(r1== NULL || r2 == NULL)
		return false;
	return is_mirror(r1->left,r2->left) && is_mirror(r1->right,r2->right);

}

/*bool is_foldable(node *root){

 if(root == NULL)
 	return true;

  mirror(root->left);

  if(is_mirror(root->left,root->right))
  	return true;

  mirror(root->left);

return false;
}*/
bool check(node *r1,node *r2){
	if(r1 == NULL && r2 == NULL)
		return true;
	if(r1 == NULL || r2 == NULL)
		return false;
	return check(r1->left,r2->right) && check(r1->right,r2->left);
}


bool is_foldable(node *root){
	return check(root->left,root->right);
}



int main(){
 node *root = new node(1);
 root->left = new node(2);
 root->right = new node(3);
 root->	->left = new node(4);
 root->left->right = new node(5);
 
 if(is_foldable(root))
 	cout<<"Folbable"<<'\n';
 else
 	cout<<"Not Foldable"<<'\n';
return 0;
}
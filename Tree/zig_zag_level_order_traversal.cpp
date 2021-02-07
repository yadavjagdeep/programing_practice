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
//=> creating binary search tree
node *BST(node *root,int val){
	if(root == NULL)
		return new node(val);
	else if(val <= root->data)
		root->left = BST(root->left,val);
	else
		root->right = BST(root->right,val);
return root;
}
void print(std::vector<int> v,int level){
	if(level%2==0){
		for(auto x:v)
			cout<<x<<" ";
	}else{
		for(auto itr = v.rbegin();itr != v.rend();++itr)
			cout<<*itr<<" ";
	}
}
void zig_zag(node *root){
	queue<node*>q;
	q.push(root);
	int level=0;
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
    print(v,level);
    level+=1;
   }
}
int main(){
	int n;cin>>n;
	node *root = NULL;
	while(n--){
		int val;cin>>val;
		root = BST(root,val);
	}
	zig_zag(root);
return 0;
}
#include <bits/stdc++.h>
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

//=> Creating BST recursive
node* BST(node *root,int val){
	if(root == NULL)
		return new node(val);
	else if(val <= root->data)
		root->left = BST(root->left,val);
	else
		root->right = BST(root->right,val);
return root;
}

/*void new_line_level_order(node *root){
	queue<pair<node*,int>>q;
	q.push(make_pair(root,0));
	int level=0;
	while(!q.empty()){
		pair<node*,int>temp = q.front();
		if(temp.second == level){          // if level of the element at
          cout<<temp.first->data<<" ";     // is same as current level then print
		}else{
			cout<<'\n'<<temp.first->data<<" ";  // else print in new line and
			level+=1;                           // change level
		}

		if(temp.first->left != NULL)
			q.push(make_pair(temp.first->left,level+1));

		if(temp.first->right != NULL)
			q.push(make_pair(temp.first->right,level+1));

	 q.pop();
	}
}*/

//=> there is one more way of level_order_new_line
//=> As at any moment in the queue all the elements are of same order
//=> we can print all the element till size of queue
void new_line_level_order(node *root){
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		int n = q.size();
		for(int i=0;i<n;i++){
			node *temp = q.front();
			cout<<temp->data<<" ";
			q.pop();
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
		}
		cout<<'\n';
	}
}


int main(){
	int n;cin>>n;
	node *root = NULL;
	while(n--){
		int val;cin>>val;
     root = BST(root,val);
	}
	new_line_level_order(root);
return 0;
}
//=> Bottom view of binary Tree is a beautiful question
//=> Intially i got intution to just do vertical traversal using 
//   unordered_map of int and vector and just print last element of vector
//   => But then after implimenting the same i found that DFS will
//   not going to help us in this problem because the value pushed in 
//   left subtree may get below to another value from right subtree

// --> So, finally taken a little help from gfg and got that level
//    order traveral with maintaining vertical slab position will help here
//    map is used over unorderd_map to maintain order


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
void view(node *root,int k){
	map<int,int>mp;
    queue<pair<int,node* >>q;
    q.push(make_pair(k,root));
   while(!q.empty()){
   	int n = q.size();
   	for(int i=0;i<n;i++){
       pair<int,node* >p = q.front();
       //cout<<p.first<<" "<<p.second->data<<'\n';
       mp[p.first] = p.second->data;
   		q.pop();
   		if(p.second->left!= NULL)
   			q.push(make_pair(p.first-1,p.second->left));
   		if(p.second->right != NULL)
   			q.push(make_pair(p.first+1,p.second->right));
   	}
   	//cout<<'\n'<<'\n';
   }
   for(auto x:mp)
   	cout<<x.second<<" ";
   }
int main(){
	int n;cin>>n;
	node *root = NULL;
	while(n--){
		int val;cin>>val;
		root = BST(root,val);
	}
   view(root,0);
return 0;
}
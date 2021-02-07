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

//=> Creating BST Recursive

node* BST(node *root,int val){
	if(root == NULL)
		return new node(val);
	else if(val <= root->data)
		root->left = BST(root->left,val);
	else
		root->right = BST(root->right,val);
return root;
}

//=> vertical Traversal Of BST
void vertical(node *root,int i,unordered_map<int,std::vector<int>> &umap){
	if(root == NULL)
		return;
	umap[i].push_back(root->data);
	vertical(root->left,i-1,umap);
	vertical(root->right,i+1,umap);
}
int main(){
	int n;cin>>n;
	node *root = NULL;
	while(n--){
		int val;cin>>val;
		root  = BST(root,val);
	}
  unordered_map<int,std::vector<int>>umap;
  vertical(root,0,umap);
for (auto it=umap.begin(); it!=umap.end(); it++)
    {
        for (int i=0; i<(int)it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
return 0;
}
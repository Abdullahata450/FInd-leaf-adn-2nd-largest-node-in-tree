#include <iostream>
using namespace std;               

class node {
 public:
  int data;
  node* left;
  node* right;

  node() {
    this->left = NULL;
    this->right = NULL;
  }
};

node* insert(node* root, int data) {
  if (root == NULL) {
    root = new node();
    root->data = data;
    return root;
  } 
  else {
    if (data <= root->data) {
      root->left = insert(root->left, data);
    } 
	else {
      root->right = insert(root->right, data);
    }
    return root;
  }
}

void find_leaf_node(node*root){
	if(root==NULL){
		return;
	}
	if(!root->left && !root->right){
		cout<<"Leaf Nodes Are : "<<root->data<<endl;
	}
	if(root->left){
		find_leaf_node(root->left);
	}
	if(root->right){
		find_leaf_node(root->right);
	}
}

void inorder(node*root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<"->"<<root->data<<" ";
	inorder(root->right);
}


void secondLargestUtil(node* root, int& count)
{

	if (root == NULL)
		return;
	secondLargestUtil(root->right, count);
	count++;
	if (count == 2)
	{
		cout << "2nd largest element is :"<< root->data << endl;
		return;
    }

	secondLargestUtil(root->left, count);
}

void secoundlastLargest(node* root)
{
	int count = 0;
	secondLargestUtil(root, count);
}











int main() {
	system("color 2"); // juts for fun-text color change ;)
  node* root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 10);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 14);
  root = insert(root, 4);
  root = insert(root, 7);
  root = insert(root, 13);
  
  cout<<"The leaf node of The root are "<<endl;
  find_leaf_node(root);
  cout<<endl;
  cout<<"The Inorder Roots are :"<<endl;
  inorder(root);
  cout<<endl;
  cout<<"\n";
  cout<<"Now finding 2nd largest Element in bst"<<endl;
  secoundlastLargest(root);
  
}
	


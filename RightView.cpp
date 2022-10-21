#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

Node* buildTree() {

	int x;
	cin>>x;

	//base case
	if(x == -1) {
		Node* root = NULL;
		return root;
	}

	//recursive case
	Node* root = new Node(x);
	root->left = buildTree();
	root->right = buildTree();
}

void rightView(Node* root, int level, int& max_level) {

	//base case
	if(root == NULL) {
		return;
	}

	if(level > max_level) {
		cout<<root->data<<" ";
		max_level = level;
	}
	rightView(root->right, level+1, max_level);
	rightView(root->left, level+1, max_level);
}

/*
void levelOrderTraversal(Node* root) {
	queue<Node*> q;

	q.push(root);

	while(!q.empty()) {
		Node* front = q.front();
		q.pop();

		cout<<front->data<<" ";
		if(front->left != NULL) {
			q.push(front->left);
		}
		if(front->right != NULL) {
			q.push(front->right);
		}
	}
	cout<<endl;
}
*/

int main() {
	Node* root = NULL;

	root = buildTree();

	levelOrderTraversal(root);

	int max_level = -1;
	rightView(root, 0, max_level);

	return 0;
}
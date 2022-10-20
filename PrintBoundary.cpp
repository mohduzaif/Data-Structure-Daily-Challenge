// Check is it a leaf Node
bool isLeaf(Node* root) {
    if(!root->left && !root->right) return true;
    return false;
}

// add all the left boundary nodes
void getLeftNodes(Node* root, vector<int>& ans) {
    Node* curr = root->left;
    while(curr) {
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left)  curr = curr->left;
        else    curr = curr->right;
    }
}

// add all the right boundary nodes
void getRightNodes(Node* root, vector<int>& ans) {       
    Node* curr = root->right;
    vector<int> temp;
    while(curr) {
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else    curr = curr->left;
    }
    for(int i=temp.size()-1; i>=0; --i) {
        ans.push_back(temp[i]);
    }
}

// add all the leaf nodes
void getLeafNodes(Node* root, vector<int>& ans) {
    if(!root)   return;
    if(isLeaf(root)) {  
        ans.push_back(root->data);
        return;
    }
    getLeafNodes(root->left, ans);
    getLeafNodes(root->right, ans);
}

vector<int> boundary(Node *root) {
    //Your code here
    
    vector<int> ans;
    
    if(!root)   return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    
    getLeftNodes(root, ans);
    getLeafNodes(root, ans);
    getRightNodes(root, ans);
    
    return ans;
}
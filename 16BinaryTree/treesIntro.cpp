#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node( int data ){
        this->data = data;
        left = right = NULL;
    }

};

Node* buildTree (vector<int> &nodes, int &idx){
    idx++;
    if(nodes[idx] == -1) {
        return NULL;
    }
    Node* rootNode = new Node(nodes[idx]);
    rootNode->left  = buildTree(nodes, idx);
    rootNode->right = buildTree(nodes, idx);
    return rootNode;
}

// we can traverse a tree in four manner:
// inorder, preorder, postorder, level order

// preorder traversal
void preTraversal(Node* root){
    if(root == NULL) {
        return;
    }
    cout<<root->data<<", ";
    preTraversal(root->left);
    preTraversal(root->right);
}

void inTraversal(Node* root){
    if(root == NULL) {
        return;
    }
    inTraversal(root->left);
    cout<<root->data<<", ";
    inTraversal(root->right);
}

void postTraversal(Node* root){
    if(root == NULL) {
        return;
    }
    postTraversal(root->left);
    postTraversal(root->right);
    cout<<root->data<<", ";
}

void levelOrder(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        
        if(curr == NULL) {
            cout<<endl;
            if(q.empty()) break;
            q.push(NULL);
        }else{
            cout<<curr->data<<", ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

    }

}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int idx = -1;
    Node* root = buildTree(nodes, idx);
    preTraversal(root);
    cout<<endl;

    inTraversal(root);
    cout<<endl;
    
    postTraversal(root);
    cout<<endl;
    
    levelOrder(root);
    cout<<endl;

    return 0;
}
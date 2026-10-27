#include <iostream>
#include <vector>
#include <queue>

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
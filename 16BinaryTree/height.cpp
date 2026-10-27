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

int height(Node* root ){
    int h = 0;
    if(!root) return 0;
    h+=1;
    h += max(height(root->left), height(root->right));
    return h;
}

int countNode(Node* root){
    int count = 0;
    if(!root) return 0;
    count += 1;
    count+= (countNode(root->left)+countNode(root->right));
    return count;
}

int sumOfNodes(Node* root){
    int sum = 0;
    if(!root) return 0;
    sum+= root->data;
    sum += (sumOfNodes(root->left)+sumOfNodes(root->right));
    return sum;
}


int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    int idx = -1;
    Node* root = buildTree(nodes, idx);

    levelOrder(root);
    cout<<endl;

    cout<<height(root)<<" no. of levels are there"<<endl;

    cout<<countNode(root)<<" no. of nodes are present in the tree"<<endl;
    
    cout<<sumOfNodes(root)<<" is the sum of the nodes"<<endl;

    return 0;

}
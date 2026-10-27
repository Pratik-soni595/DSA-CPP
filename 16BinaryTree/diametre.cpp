#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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

int diameter(Node* root){
    int dcurr = 0;
    if(!root) return 0;

    int lh = height(root->left);
    int rh = height(root->right);
    dcurr = lh + rh + 1;

    return max({dcurr, diameter(root->left), diameter(root->right)});
}

pair<int, int> optimizedDiameter(Node* root) {
    if (!root) {
        return {0, 0};
    }

    pair<int, int> left = optimizedDiameter(root->left);
    pair<int, int> right = optimizedDiameter(root->right);

    int lh = left.second;
    int rh = right.second;

    pair<int, int> ans;

    ans.first = max({lh + rh + 1, left.first, right.first});
    ans.second = max(lh, rh) + 1;

    return ans;
}

int main(){
    vector<int> nodes = {1,2,4,8,9,-1,-1,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    int idx = -1;
    Node* root = buildTree(nodes, idx);
    levelOrder(root);
    cout<<endl;
    cout<<"diameter: "<<optimizedDiameter(root).first;
}
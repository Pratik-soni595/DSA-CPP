#include<iostream>
#include<vector>

using namespace std;

class Node{
public: 
    int data;
    Node* next;

    Node(int n){
        this->data = n;
        this->next = NULL;
    }
};



class Queue{
    Node* head;
    Node* tail;
public:
    Queue(){
        this->head = NULL;
        this->tail = NULL;
    }

    void push(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            this->head = newNode;
            this->tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop(){
        if(empty()) {
            cout<<"Empty queue"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    int front(){
        if(empty()) return -1;
        return head->data;
    }
    bool empty(){
        return head == NULL;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout<<q.front();
        q.pop();
    }
    return;
}

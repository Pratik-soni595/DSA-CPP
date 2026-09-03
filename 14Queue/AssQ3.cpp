#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void reverseK(int k, queue<int> q){
    stack<int> s;
    int n = q.size();
    for(int i = 0; i<k; i++){
        s.push(q.front());
        q.pop();
    }

    for(int i = 0; i<k ; i++){
        q.push(s.top());
        s.pop();
    }
    for(int i = 0; i<n-k; i++){
        q.push(q.front());
        q.pop();
    }

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main (){
    queue<int> q;
    for(int i = 1; i<8; i++){
        q.push(i);
    }
    
    reverseK(3, q);
    return 0;
}
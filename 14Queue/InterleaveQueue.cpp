#include<iostream>
#include<queue>
using namespace std;

void interleave(queue<int> &org){
    queue<int> first;
    int size = org.size();
    for(int i = 0 ; i<size/2; i++){
        first.push(org.front());
        org.pop();
    }

    while(!first.empty()){
        org.push(first.front());
        org.push(org.front());

        first.pop();
        org.pop();
    }
}

int main(){
    queue<int> org;
    for(int i = 1; i<=10; i++){
        org.push(i);
    }
    
    interleave(org);
    
    for(int i = 1; i<=10; i++){
        cout<<org.front()<<endl;
        org.pop();
    }
    



}
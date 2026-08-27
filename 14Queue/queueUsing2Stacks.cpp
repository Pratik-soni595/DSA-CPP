#include<iostream>
#include<stack>

using namespace std;

class Queue{
    stack<int> s1;
    stack<int> s2;
public:
    void push(int data){
        s1.push(data);
    }
    void pop(){
        if(s1.empty()){
            cout<<"Queue is empty";
            return;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int front(){
        if(s1.empty()){
            cout<<"Queue is empty";
            return;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
};

class Queue2{
    stack<int> s1;
    stack<int> s2;
public:
    void push(int data){

        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(data);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop(){
        s1.pop();
    }

    int front(){
        return s1.top();
    }
};



int main(){
    

}
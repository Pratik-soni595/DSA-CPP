#include <iostream>
using namespace std;


class Queue {
    int* arr;
    
    int capacity;
    int currSize;

    int f;
    int r;

    Queue (int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;
        f = r = -1;
    }
    void push(int data){
        if(currSize == capacity){
            cout<<"Queue is full"<<endl;
            return;
        }
        r = (r+1) % capacity;
        arr[r] = data;
        currSize ++;
    }
    void pop(){
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        f = (f+1) % capacity;
        currSize--;

    }
    int front(){
        if(empty()){
            cout<<"Queue is empty";
            return -1;
        }
        return arr[f];
    }
    bool empty(){
        if(currSize == 0){
            return true;
        }
    }
};
#include <iostream>
#include <deque>

using namespace std;

// deque : double ended queue

int main(){
    deque<int> dq;
    dq.push_front(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_back(4);

    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    return 0;
}
#include<iostream>
#include<queue>

using namespace std;

void firstNonRepeatingChar(string s){
    queue<char> q;
    int freq[26] = {0};

    for(int i = 0; i<s.size(); i++){
        char ch = s[i];
        q.push(ch);
        freq[ch-'a'] ++;

        while(!q.empty() && freq[q.front()-'a'] > 1){
            q.pop();
        }
        if(q.empty()) {
            cout<<"-1\n";
        }else {
            cout<<q.front()<<"\n";
        }
    }
}
int main(){
    string str = "aabxccb";
    firstNonRepeatingChar(str);
}
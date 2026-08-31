#include<iostream>
#include<queue>

using namespace std;

int clacTime(int k, int arr[], int n){
    queue<int> q;
    for(int i = 0; i<n; i++){
        q.push(arr[i]);
    }

    int i = 0, ans = 0;
    while(!q.empty()){
        if(arr[i]){
            q.pop();
            ans ++;
            arr[i] --;
            if(arr[i]){
                q.push(arr[i]);

            }else if(i==k && arr[i] == 0){
                return ans;
            }
        }

        i = (i+1)%n;
    }
}

int main(){
    int arr[] = {2,2,2};
    int k = 1;
    cout<<clacTime(k, arr, 3);
}
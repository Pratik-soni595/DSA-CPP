#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int indianCoins(int v){
    vector<int> denominations = {1,2,5,10, 20, 50, 100, 200, 500, 2000};
    int n = denominations.size();
    int rem = v;
    int ans = 0;
    for(int i = n-1; i>=0; i--){
        if(rem == 0) return ans;
        if(rem>=denominations[i]){
            ans ++;
            rem -= denominations[i];
            cout<<denominations[i]<<endl;
            i++;
        }
    }
    return ans;

}

int main (){
    int v = 485;
    cout<<indianCoins(v);
}
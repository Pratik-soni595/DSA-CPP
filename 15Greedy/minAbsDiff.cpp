#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void minAbsDiff(vector<int> v1, vector<int> v2){
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int absDiff = 0;
    for(int i = 0; i<v1.size(); i++){
        absDiff += abs(v1[i]-v2[i]);
    }
    cout<<absDiff<<endl;
}

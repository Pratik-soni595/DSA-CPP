#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int actSelection(vector<int> start, vector<int> end){
    // considering end is sorted
    int n = start.size();
    int currEnd = end[0];
    int count  = 1;

    for(int i = 1; i<n; i++){
        if(currEnd<=start[i]){
            currEnd = end[i];
            count++;
        }

    }

    return count;
}


bool compare(pair<int, int> p, pair<int, int> q){
    return p.second<q.second;
}


int main(){

    // vector<int> start = {1,3,0,5,8,5};
    // vector<int> end = {2,4,6,7,9,9};
    // cout<<actSelection(start, end);

    vector<int> start = {0,1,2};
    vector<int> end = {9,2,4};
    
    vector<pair<int, int>> activity(3, make_pair(0,0));

    activity[0] = make_pair(0, 9);
    activity[1] = make_pair(1, 2);
    activity[2] = make_pair(2, 4);

    sort(activity.begin(), activity.end(), compare);

    for(int i =0 ; i<3; i++){
        cout<<activity[i].first<<", "<<activity[i].second<<endl;
    }

}
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second>p2.second;
}

int jobSequencing(vector<pair<int, int>> jobs){
    sort(jobs.begin(), jobs.end(), compare);
    // now the jobs are arranged in descending order with respect to their profits
    int profit = jobs[0].second;
    int safeDead = jobs[0].first +1;

    for(int i = 1; i<jobs.size(); i++){
        if(jobs[i].first>=safeDead){
            profit+= jobs[i].second;
            safeDead++;
        }
    }
    return profit;
}


int main (){
    vector<pair<int, int>> jobs(4, make_pair(0, 0));

    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 40);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    cout<<jobSequencing(jobs);
}
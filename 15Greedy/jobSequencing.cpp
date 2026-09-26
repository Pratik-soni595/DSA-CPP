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
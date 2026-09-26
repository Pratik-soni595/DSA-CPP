#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second<p2.second;
}

int maxLength(vector<pair<int, int>> pairs){
    sort(pairs.begin(), pairs.end(), compare);

    int lastEnd = pairs[0].second ;
    int maxLen = 1;
    for(int i = 1; i<pairs.size(); i++){
        if(pairs[i].first>=lastEnd){
            maxLen++;
            lastEnd = pairs[i].second;
        }
    }
}
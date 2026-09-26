#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<pair<float, float>, float> p1, pair<pair<float, float>, float> p2){
    return p1.second>p2.second;
}

int knapSack(vector<float> weights, vector<float> values, float capacity){
    

    //we need to sort in descending order according to ratios

    vector<pair<pair<float, float>, float>> trio;

    for(int i = 0; i<weights.size(); i++){
        trio.push_back(make_pair(make_pair(weights[i], values[i]), values[i]/weights[i]));
    }

    sort(trio.begin(), trio.end(), compare);

    // now we have sorted in the required order
    float c2 = capacity;
    float totalVal = 0;

    int i = 0;
    while(c2>0 && i<trio.size()){
        if(trio[i].first.first>=c2){
            totalVal += c2*trio[i].second;
            c2= 0;
        }else{
            totalVal+=trio[i].first.second;
            c2-=trio[i].first.first;
        }
        i++;
    }

    return totalVal;
}
#include<iostream>
using namespace std;

int gasStation(int gas[], int cost[], int n){ // solution is correct, but time complexity is O(n^2) not optimal
    for(int i = 0; i < n; i++){
        if(gas[i]>=cost[i]){
            int stIndex = i;
            int leftFuel = 0;
            int j=stIndex;
            
            do{
                if(leftFuel+gas[j] >= cost[j]){
                    leftFuel = leftFuel+gas[j]-cost[j];
                    j = (j+1) % n;
                }else{
                    break;
                }
            }while(j!=stIndex);
            if(j==stIndex) return stIndex;
        }
    }
    return -1;
}

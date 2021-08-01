#include<iostream>
#include<vector>
#define INT_MIN -23113
using namespace std;

int findBestStation(vector<int> &gas, vector<int> &cost){
    // If the total sum of gas - total sum of cost >=0 it means that there is a solution for sure
    // Start with 0 as the proposed starting point
    // If you find a gas station where the net gas upto now becomes negative, change the starting point to i+1
    // Since the total sum of gas>=total sum of cost and the gas-cost upto now is <0, the gas - cost for the remaining part of the array should be positive for sure. 

    int tank = 0,startIdx = 0,totalSum=0,n = gas.size();
    
    for(int i=0; i<n; i++){
        tank+=gas[i]-cost[i];
        totalSum+=gas[i]-cost[i];
        if(tank<0){
            tank = 0;
            startIdx = i+1;
        }
    }
    if(totalSum<0)return -1;
    return startIdx;

}

int main(){
    vector<int> A = {4,6,7,4};
    vector<int> B = {6,5,3,5};
    cout<<findBestStation(A,B)<<endl;
    return 0;
}
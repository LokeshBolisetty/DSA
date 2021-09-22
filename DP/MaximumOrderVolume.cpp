#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Find the maximum volume with no intersecting calls
int maxVolume(vector<int>& start, vector<int>& duration, vector<int>& volume) {
    int n = start.size();
    //First row is if you attend the call
    //Second row is if you don't attend the call
    vector<vector<pair<int,int>>> dp2(2,vector<pair<int,int>>(n,{0,0}));
    //The first value in the pair is the actual volume so far. 
    //The second value in the pair is the max time required. 
    dp2[1][0] = {volume[0],duration[0]};
    for(int i=1;i<n;i++){
        dp2[0][i] = max(dp2[0][i-1],dp2[1][i-1]);
        int take = max(dp2[0][i-1].first,dp2[1][i-1].first);
        if(start[i]>dp2[0][i-1].second){
            take = max(take,volume[i]+dp2[0][i-1].first);
        }
        if(start[i]>dp2[1][i-1].second){
            take = max(take,volume[i]+dp2[1][i-1].first);
        }
        dp2[1][i] = {take,start[i]+duration[i]};
    }
    return max(dp2[0][n-1].first,dp2[1][n-1].first);
}

int main(){
    vector<int> start = {1,2,4};
    vector<int> duration = {2,2,1};
    vector<int> volume = {1,2,3};
    cout<<maxVolume(start, duration, volume)<<endl;
}
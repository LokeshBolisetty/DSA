/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void back(vector<int> &candidates, int target,vector<vector<int>> &ans,vector<int> &curr,int idx){
        if(target==0){
        ans.push_back(curr);
        return;
    }
    if(idx==candidates.size() || candidates[idx]>target)return;
    // while(idx<candidates.size() && target-candidates[idx]>=0) {
    //     curr.push_back(candidates[idx]);
    //     back(candidates,target-candidates[idx],ans,curr,idx);
    //     idx++;
    //     curr.pop_back();
    // }
    curr.push_back(candidates[idx]);
    back(candidates,target-candidates[idx],ans,curr,idx);
    curr.pop_back();
    back(candidates,target,ans,curr,idx+1);
}

vector<vector<int>> combinationSum(vector<int> &candidates,int target){
    vector<vector<int>> answer;
    vector<int> curr;
    sort(candidates.begin(),candidates.end());
    back(candidates,target,answer,curr,0);
    return answer;
}

int main(){
    vector<int> candidates = {1,2};
    int target = 4;
    vector<vector<int>> answer = combinationSum(candidates,target);
    for(auto x: answer){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
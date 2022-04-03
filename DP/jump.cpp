/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.
*/

#include<iostream>
#include<vector>
using namespace std;

int jump(vector<int>& nums) {
    vector<int> dp(nums.size(),INT32_MAX);
    dp[0] = 0;
    for(int i=0;i<dp.size();i++){
        if(dp[i] == INT32_MAX)continue;
        for(int j = i+1;j<=i+nums[i] && j<nums.size();j++){
            dp[j] = min(dp[j],dp[i]+1);   
        }
    }
    // for(int i=0;i<nums.size();i++){
    //     cout<<dp[i]<<" ";
    // }
    return dp[nums.size()-1];
}

int main(){
    
    vector<int> A = {2,3,1,1,4};
    cout<<jump(A)<<endl;
    return 0;
}
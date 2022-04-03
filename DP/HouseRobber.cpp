/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


int houseRobberWithLimits(vector<int> &nums,int low, int high){
    int n = high - low;
    if(n<=1)return n==1?nums[low]:0;
    if(n==2)return max(nums[low+1],nums[low]);
    vector<int> dp(n);
    dp[0] = nums[low];
    dp[1] = max(nums[low],nums[low + 1]);
    for(int i=low+2;i<high;i++){
        dp[i-low] = max(dp[i-1-low],dp[i-2-low]+nums[i]);
    }
    return dp[n-1];
}

int circularHouseRobber(vector<int> &nums){
    int n = nums.size();
    int max1 = nums[0] + houseRobberWithLimits(nums,2,n-1);
    int max2 = houseRobberWithLimits(nums,1,n);
    return max(max1,max2);  
}

int houseRobber(vector<int> &nums){
    int n = nums.size();
    if(n==1)return nums[0];
    if(n==2)return max(nums[1],nums[0]);
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);
    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[n-1];
}

int main(){
    vector<int> nums = {0};
    cout<<circularHouseRobber(nums)<<endl;
    return 0;
}
/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/

#include<vector>
#include<iostream>
using namespace std;

bool canJump(vector<int>& nums) {
    int maxValue = 0;
    int current = 0;
    while(current<=maxValue && current<nums.size()){
        maxValue = max(maxValue, current + nums[current]);
        if(maxValue>=nums.size()-1)return true;
        current++;
    }
    return current==nums.size();
}

bool canJumpDp(vector<int>& nums) {
    if(nums.size()==0)return false;
    vector<bool> dp(nums.size(),false);
    dp[0] = true;
    for(int i =0;i<nums.size();i++){
        if(dp[i]==false)continue;
        int maxLength = nums[i];
        for(int j = i+1;j<=i+maxLength && j<nums.size();j++){
            if(j==nums.size()-1)return true;
            dp[j] =true;
        }
    }
    return dp[nums.size()-1];
}

int main(){
    vector<int> A = {3,2,1,0,4};
    cout<<boolalpha<<canJump(A)<<endl;
    return 0;
}
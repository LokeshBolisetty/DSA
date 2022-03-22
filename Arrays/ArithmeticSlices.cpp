/*
An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.
*/

#include<iostream>
#include<vector>
using namespace std;

int ArithmeticSlices(vector<int> &nums){
    int count; //Stores the number of ArithmeticSlices seen so far
    //We shall count the number of subarrays from every i from 0 to nums.size()-2
    for(int i=0;i<nums.size()-2;i++){
        int diff = nums[i+1]-nums[i];
        for(int j=i+2;j<nums.size();j++){
            if(nums[j]-nums[j-1]==diff)count++;
            else break;
        }
    }
    return count;
}

int main(){

    return 0;
}
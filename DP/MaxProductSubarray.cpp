/*
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    //Let's try Kadane's Algorithm
    //Won't work. Kadane's algo witll not choose negative numbers. But if you have two negative numbers, 
    //then their product will be positive. It can be the answer that Kadane's will ignore
    
    
    //In order to manage the negative numbers also, we need to maintain not only the maxSoFar but also the minSoFar. 
    //When you encounter a negative number, the new maximum could be n*minSoFar
    
    int minSoFar = 1,maxSoFar = 1;
    int answer = *max_element(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            maxSoFar = 1;
            minSoFar = 1;
            continue;
        }
        int temp = maxSoFar*nums[i];
        maxSoFar = max(nums[i],max(maxSoFar*nums[i],minSoFar*nums[i]));
        minSoFar = min(nums[i],min(temp,minSoFar*nums[i]));
        answer = max(answer,max(maxSoFar,minSoFar));
    }
    return answer;
}


int main(){
    vector<int> A = {2,3,-2,4};
    cout<<"The maximum product is "<<maxProduct(A)<<endl;
    return 0;
}
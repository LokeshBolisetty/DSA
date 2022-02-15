/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    //Only difference in implementation of NextGreaterElementI and this is that here we 
    //consider elements upto 2*nums.size()-1 instead of nums.size()
    //That is because we are told that the array is circular. 
    //So we have to consider elements upto nums.size() from every element.
    //We basically do two passes instead of one. 
    //https://leetcode.com/problems/next-greater-element-ii/solution/ has a nice illustration about how this works 

    //Note: Leetcode tells to store indicies in stack instead of numbers 
    //because duplicate elements can cause problems.
    //But this solution works fine in the submission. 
    vector<int> answer(nums.size());
    stack<int> s;
    for(int i=2*nums.size()-1;i>=0;i--){
        while(!s.empty() && s.top()<nums[i%nums.size()]){
            s.pop();
        }
        if(s.empty()){
            answer[i%nums.size()] = -1;
        }else{
            answer[i%nums.size()] = s.top();
        }
        s.push(nums[i%nums.size()]); 
    }
    return answer;
}

int main(){
    vector<int> nums = {1,3,5,2,4};
    vector<int> ans = nextGreaterElements(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
*/

#include<iostream>
#include<vector>
using namespace std;

int nextGreatest(vector<int> &A, int idx){
    for(int i=idx+1;i<A.size();i++){
        if(A[i]>A[idx])return A[i];
    }
    return -1;
}
//This is not the optimal solution. Check Stacks and Queues folder for optimal solution. 
//This passes all the testcases on leetcode though. 
vector<int> nextGreaterElement(vector<int> &nums1,vector<int> &nums2){
    vector<int> ans;
    for(int i=0;i<nums1.size();i++){
        for(int j=0;j<nums2.size();j++){
            if(nums2[j]==nums1[i]){
                ans.push_back(nextGreatest(nums2,j));
                break;
            }
        }
    }
    return ans;
}
int main(){
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> ans = nextGreaterElement(nums1,nums2);
    return 0;
}
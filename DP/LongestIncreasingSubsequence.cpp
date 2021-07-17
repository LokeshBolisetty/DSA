/*
Find the longest increasing subsequence of a given array of integers, A.

In other words, find a subsequence of array in which the subsequence’s elements are in strictly increasing order, and in which the subsequence is as long as possible.
This subsequence is not necessarily contiguous, or unique.
In this case, we only care about the length of the longest increasing subsequence.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

int LongestIncreasingSubsequence(vector<int> A){
    //The problem does have a lot of subproblems in it. 
    //Let LIS be the array Longest Increasing Subsequence
    //LIS(i) = 1+max(LIS(j)) where 0<=j<=i and arr[j]<arr[i]
    //       = 1 if no such j exists
    //So in the array {1,2,1,5}
    //LIS(3) = 1+max(LIS(0),LIS(1),LIS(2))
    //LIS(0) = 1
    //LIS(1) = 1+LIS(0) because 1<2
    //LIS(1) = 1+1 = 2
    //LIS(2) = 1 + max(LIS(1),LIS(0))
    //LIS(2) = 1 + max(0) //LIS(2) is not added because 1 is not less than 1
    //LIS(2) = 2
    //LIS(4) = 1+2 = 3
    //Now we can use memorization techniques to store the values of sub problems
    //so that we can get the solution in O(n) time
    int n = A.size();
    if(n==0)return n;
    vector<int> dp(n,1);
    int answer = 1;
    for(int i=1;i<n;i++){
        int ele=INT_MIN;
        for(int j=0;j<i;j++){
            if(A[j]<A[i])dp[i] = max(dp[i],dp[j]+1); 
        }
        if(dp[i]>answer)answer=dp[i];
    }
    return answer;
}


int main(){
    vector<int> A = { 69, 54, 19, 51, 16, 54, 64, 89, 72, 40, 31, 43, 1, 11, 82, 65, 75, 67, 25, 98, 31, 77, 55, 88, 85, 76, 35, 101, 44, 74, 29, 94, 72, 39, 20, 24, 23, 66, 16, 95, 5, 17, 54, 89, 93, 10, 7, 88, 68, 10, 11, 22, 25, 50, 18, 59, 79, 87, 7, 49, 26, 96, 27, 19, 67, 35, 50, 10, 6, 48, 38, 28, 66, 94, 60, 27, 76, 4, 43, 66, 14, 8, 78, 72, 21, 56, 34, 90, 89};
    cout<<LongestIncreasingSubsequence(A)<<endl;
    return 0;
}
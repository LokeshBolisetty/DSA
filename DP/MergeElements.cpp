/*
Given an integer array A of size N. You have to merge all the elements of the array into one with the minimum possible cost.

The rule for merging is as follows:

Choose any two adjacent elements of the array with values say X and Y and merge them into a single element with value (X + Y) paying a total cost of (X + Y).

Return the minimum possible cost of merging all elements.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define INT_MAX 2147808
using namespace std;

int MergeElements(vector<int> &A){
    //Basic idea is to store MergeElements(i,j) and use it later
    //MergeElements(i,j) is the answer of merging elements according to question
    // from index i to index j
    //Then MergeElements(i,j) = min(dp[i][j],sum[i][j]+dp[i][k]+dp[k+1][j]) for every i<=k<=j
    
    //To store the sum of all elements upto given index
    //This can help find sum(i,j) in O(1) time
    vector<int> pre;
    pre.push_back(0);
    pre.push_back(A[0]);
    int n = A.size();
    for(int i=1;i<n;i++){
        pre.push_back(pre[i]+A[i]);
    }

    //To memorize the answers of subparts
    vector<vector<int>> dp(n+1,vector<int>(n+1));

    //The cost of meging an array with size 1 is always 0
    for(int i=0;i<=n;i++){
        dp[i][i]=0;
    }

    //For length greater than 1
    for(int len=2;len<=n;len++){ //In such question always use len only coz we need answers for all smaller length arrays first
        for(int i=1;i<=n-len+1;i++){
            int j = i+len-1;
            int sum = pre[j]-pre[i-1];
            dp[i][j] = INT_MAX;
            for(int k= i;k<j;k++){
                dp[i][j]= min(dp[i][j],sum+dp[i][k]+dp[k+1][j]);
            }
        }
    }
    return dp[1][n];
}

int main(){
    vector<int> A = {1,3,7};
    cout<<MergeElements(A)<<endl;
    return 0;
}
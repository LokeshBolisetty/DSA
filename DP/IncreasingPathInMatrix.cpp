/*
Given a n*n matrix where all numbers are distinct, find the maximum length path (starting from any cell) such that all cells along the path are in increasing order with a difference of 1. 
We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1) with the condition that the adjacent cells have a difference of 1.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define INT_MIN -2147483647
using namespace std;

int calculateLongestPath(vector<vector<int>> A){
    //Doesn't work. If you calcaulate in all four directions you 
    //might recount sometimes. So if you calculate only in forward directions, 
    //you might miss some cases. So this approach can't be used for an efficient solution here. 
    //So instead of this find out the longest path from each cell. 
    vector<vector<int>> dp(A.size(),vector<int>(A.size(),1));
    int ans = 1;
    int n = A.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i+1<n && abs(A[i][j]-A[i+1][j])==1){
                dp[i+1][j]+=dp[i][j];
                if(ans<dp[i+1][j])ans = dp[i+1][j];
            }
            if(j+1<n && abs(A[i][j]-A[i][j+1])==1){
                dp[i][j+1]+=dp[i][j];
                if(ans<dp[i][j+1])ans = dp[i][j+1];
            }
        }
    }
    return ans;
}   

int longestPath(int i,int j,vector<vector<int>> &A,vector<vector<int>> &dp){
    int n = A.size();
    
    if(i<0 || i>=n || j<0||j>=n)return 0;
    //If the problem has already been solved previously, use it
    if(dp[i][j]!=-1)return dp[i][j];

    //Store the longest possible distances in all the four directions
    int x=INT_MIN,y = INT_MIN,z = INT_MIN,w=INT_MIN;
    if(j<n-1 && (A[i][j]+1==A[i][j+1]))x = 1+longestPath(i,j+1,A,dp);
    if(j>0 && (A[i][j]+1==A[i][j-1]))y = 1+longestPath(i,j-1,A,dp);
    if(i>0 && (A[i][j]+1==A[i-1][j]))z = 1+longestPath(i-1,j,A,dp);
    if(i<n-1 && (A[i][j]+1==A[i+1][j]))w = 1+longestPath(i+1,j,A,dp);
    dp[i][j] = max(x,max(y,max(z,max(w,1))));
    return dp[i][j];
}

int longestOfAll(vector<vector<int>> &A){
    int result = 1;
    vector<vector<int>> dp(A.size(),vector<int>(A.size(),-1));
    int n = A.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]==-1)
                longestPath(i,j,A,dp);
            result = max(result,dp[i][j]);
        }
    }
    return result;
}

int main(){
    vector<vector<int>> A = {{1,2,9},
                             {5,3,8},
                             {4,6,7}};
    cout<<longestOfAll(A)<<endl;
    return 0;
}
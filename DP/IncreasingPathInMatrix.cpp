/*
Given a 2D integer matrix A of size N x M.

From A[i][j] you can move to A[i+1][j], if A[i+1][j] > A[i][j], or can move to A[i][j+1] if A[i][j+1] > A[i][j].

The task is to find and output the longest path length if we start from (0, 0).

NOTE:

If there doesn't exist a path return -1.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define INT_MIN -2147483647
using namespace std;

int calculateIncreasingPath(vector<vector<int>> &A){
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    dp[0][0]=1;
    //Filling the first row
    for(int i=1;i<m;i++){
        if(A[0][i-1]<A[0][i] && dp[0][i-1]!=-1)
            dp[0][i] = dp[0][i-1]+1;
    }
    //Filling the first column
    for(int i=1;i<n;i++){
        if(A[i-1][0]<A[i][0] && dp[i-1][0]!=-1)
            dp[i][0] = dp[i-1][0]+1;
    }
    //For the remaining elements 
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(A[i-1][j]<A[i][j] && dp[i-1][j]!=-1)dp[i][j] =max(dp[i][j],dp[i-1][j]+1);
            if(A[i][j-1]<A[i][j] && dp[i][j-1]!=-1)dp[i][j] = max(dp[i][j],dp[i][j-1]+1);
        }
    }
    return dp[n-1][m-1];
}

int main(){
    vector<vector<int>> A = {{1,2,9},
                             {5,3,8},
                             {4,6,7}};
    cout<<calculateIncreasingPath(A)<<endl;
    return 0;
}
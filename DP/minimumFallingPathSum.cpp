/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. 
Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/

#include<iostream>
#include<vector>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n,vector<int>(n));
    dp[n-1] = matrix[n-1];
    int answer=INT32_MAX;
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<n;j++){
            int a = INT32_MAX, b = dp[i+1][j], c = INT32_MAX;
            if(j-1>=0)a = dp[i+1][j-1];
            if(j+1<n)c = dp[i+1][j+1];
            dp[i][j] = matrix[i][j]+min(a,min(b,c));
        }
    }
    for(int i=0;i<dp[0].size();i++){
        answer = min(answer, dp[0][i]);
    }
    return answer;
}

int main(){
    vector<vector<int>> A = {{2,1,3},{6,5,4},{7,8,9}};
    cout<<minFallingPathSum(A)<<endl;
    return 0;
}
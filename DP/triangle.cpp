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
    vector<vector<int>> dp(n-1);
    dp.push_back(matrix[n-1]);
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            int a = dp[i+1][j], b = INT32_MAX;
            if(j+1<=i+1)b = dp[i+1][j+1];
            dp[i].push_back(matrix[i][j]+min(a,b));
        }
    }
    return dp[0][0];
}

int main(){
    vector<vector<int>> A = {{-1},{-2,-3}};
    cout<<minFallingPathSum(A)<<endl;
    return 0;
}
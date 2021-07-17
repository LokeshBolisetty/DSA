/*
There are a row of N houses, each house can be painted with one of the three colors: red, blue or green.

The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a N x 3 cost matrix A.

For example, A[0][0] is the cost of painting house 0 with color red; A[1][2] is the cost of painting house 1 with color green, and so on.

Find the minimum total cost to paint all houses.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int PaintHouse(vector<vector<int>> &A){
    vector<vector<int>> dp(A.size(),vector<int>(3));
    dp[0][0] = A[0][0];
    dp[0][1] = A[0][1];
    dp[0][2] = A[0][2];
    for(int i=0;i<A.size();i++){
        //If you have to paint the ith element only with Red colour,
        //What is the least cost your could get?
        //It is equal to the cost of painting this house with Red
        //                      +mincost of painting the prev house with either blue or green
        dp[i][0] = min(dp[i-1][1],dp[i-1][2])+A[i][0];

        //If you have to paint ith element only with Blue colour,
        //What is the least cost you could get? 
        //It is equal to the cost of painting this house with Blue
        //                      + mincost of painting the prev house with either red or green
        dp[i][1]  = min(dp[i-1][0],dp[i-1][2])+A[i][1];

         //If you have to paint ith element only with Green colour,
        //What is the least cost you could get? 
        //It is equal to the cost of painting this house with Green
        //                      + mincost of painting the prev house with either red or blue
        dp[i][2] = min(dp[i-1][0],dp[i-1][1])+A[i][2];
    }
    return min(min(dp[A.size()-1][0],dp[A.size()-1][1]),dp[A.size()-1][2]);
}

int main(){
    vector<vector<int>> A = {{1,2,3},
                             {10,11,12}};
    cout<<PaintHouse(A)<<endl;
    return 0;
}
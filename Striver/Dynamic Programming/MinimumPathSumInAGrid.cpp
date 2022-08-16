#include<iostream>
#include<vector>

using namespace std;

//Helper for memorization DP
int findCost(vector<vector<int>> &grid, vector<vector<int>> &dp, int x, int y){
    int n = grid.size(), m = grid[0].size();
    if(x==0 && y==0)return grid[0][0];
    if(x<0 || y<0)return INT32_MAX;
    if(dp[x][y]!=-1)return dp[x][y];
    return grid[x][y]+min(findCost(grid, dp, x-1, y), findCost(grid, dp, x, y-1));
}

//Memorization DP
//This is recursive while storing the solutions found so far but this was giving TLE. 
//Might be becaus of too many function calls. 
int minSumPathMemorization(vector<vector<int>> &grid){
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),-1));
    return findCost(grid, dp, grid.size()-1, grid[0].size()-1);
}

//Tabulation DP
int minSumPath(vector<vector<int>> &grid) {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),-1));
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(i==0 && j==0){
                dp[i][j] = grid[i][j];
                continue;
            }
            int a = INT32_MAX, b = INT32_MAX;
            if(i>0)a = dp[i-1][j];
            if(j>0)b = dp[i][j-1];
            dp[i][j] = grid[i][j]+min(a, b);
        }
    }
    return dp[grid.size()-1][grid[0].size()-1];
}

int main(){
    int n = 2, m = 3;
    vector<vector<int>> grid = {{5,9,6},{11,5,2}};
    cout<<minSumPath(grid)<<endl;
    return 0;
}
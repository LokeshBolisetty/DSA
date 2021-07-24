#include<iostream>
#include<vector>
using namespace std;
#define int long long 
int countUniquePaths(vector<vector<int>> &A){
    int m = A.size();
    int n = A[0].size();

    // Base case: If the grid is a 1x1 grid
    // If the starting cell itself is an obstacle, you can not reach there so 0
    // If its not an obstacle, you can go there in one way (The direct path (0,0))
    if(m==1 && n==1)return abs(1-A[0][0]);

    //grid stores the answers to subproblems
    //For example, grid[3][2] stores the answer for going from grid[0][0] to grid[2][1]
    vector<vector<int>> grid(m+1,vector<int>(n+1,0));

    //Initializing the grid. There is only one way to go to (0,0) which is the direct path.
    grid[1][1] = 1;

    //For remaining positions on the grid
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            //If the current cell, is an obstacle, no one can reach there, so the number of ways to current cell is 0 always. 
            if(A[i-1][j-1]==1)continue;

            //If the left cell is not an obstacle, you can go from left cell to current cell. 
            if(A[i-2][j-1]!=1)grid[i][j]+=grid[i-1][j];

            //If the cell above is not an obstacle, you can go from top cell to current cell
            if(A[i-1][j-2]!=1)grid[i][j]+=grid[i][j-1];
        }
    }
    return grid[m][n];
}
signed main(){
    vector<vector<int>> A = {{0,0,0},
                             {0,1,0},
                             {0,0,0}};
    cout<<countUniquePaths(A)<<endl;
    return 0;
}
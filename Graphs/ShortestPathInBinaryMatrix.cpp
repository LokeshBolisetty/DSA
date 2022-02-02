/*
Question:
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

    All the visited cells of the path are 0.
    All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//The trick in this question is to mark the cell as visited when you are adding them to the queue itself. 
//Generally we mark a cell visited when we take it out of the queue, but that might result in TLE for large testcases.

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid.size()==0 || grid[0][0]==1)return -1;
    int n = grid.size();
    if(grid[n-1][n-1])return -1;
    queue<vector<int>>  q;
    q.push({0,0,1});
    grid[0][0] = 1;
    while(!q.empty()){
        int x =  q.front()[0];
        int y =  q.front()[1];
        int steps = q.front()[2];
        // Do not mark the cell as visited here grid[x][y] = 1;
        q.pop();
        if(x==n-1 && y==n-1) return steps;
        if(x>=0 && x<n && y-1>=0 && y-1<n && grid[x][y-1]==0){
            if(x==n-1 && y-1==n-1)return steps+1;
            grid[x][y-1]=1; //Instead mark them as visited at this point itself. 
            q.push({x,y-1,steps+1});
        }
        if(x>=0 && x<n && y+1>=0 && y+1<n && grid[x][y+1]==0){
            if(x==n-1 && y+1==n-1)return steps+1;
            grid[x][y+1]=1;
            q.push({x,y+1,steps+1});
        }
        if(x+1>=0 && x+1<n && y>=0 && y<n && grid[x+1][y]==0){
            if(x+1==n-1 && y==n-1)return steps+1;
            grid[x+1][y]=1;
            q.push({x+1,y,steps+1});
        }
        if(x-1>=0 && x-1<n && y>=0 && y<n && grid[x-1][y]==0){
            if(x-1==n-1 && y==n-1)return steps+1;
            grid[x-1][y]=1;
            q.push({x-1,y,steps+1});
        }
        if(x-1>=0 && x-1<n && y-1>=0 && y-1<n && grid[x-1][y-1]==0){
            if(x-1==n-1 && y-1==n-1)return steps+1;
            grid[x-1][y-1]=1;
            q.push({x-1,y-1,steps+1});
        }
        if(x+1>=0 && x+1<n && y+1>=0 && y+1<n && grid[x+1][y+1]==0){
            if(x+1==n-1 && y+1==n-1)return steps+1;
            grid[x+1][y+1]=1;
            q.push({x+1,y+1,steps+1});
        }
        if(x-1>=0 && x-1<n && y+1>=0 && y+1<n && grid[x-1][y+1]==0){
            if(x-1==n-1 && y+1==n-1)return steps+1;
            grid[x-1][y+1]=1;
            q.push({x-1,y+1,steps+1});
        }
        if(x+1>=0 && x+1<n && y-1>=0 && y-1<n && grid[x+1][y-1]==0){
            if(x+1==n-1 && y-1==n-1)return steps+1;
            grid[x+1][y-1]=1;
            q.push({x+1,y-1,steps+1});
        }
    }
    return -1;
}
int main(){
    vector<vector<int>> grid = {{1,0,0},{1,1,0},{1,1,0}};
    cout<<shortestPathBinaryMatrix(grid)<<endl;
    return 0;
}
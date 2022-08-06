/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int numIslands(vector<vector<char>>& grid) {
    int islands = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(),false));
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]=='1' && !visited[i][j]){
                islands++;
                queue<pair<int, int>> q;
                q.push({i,j});
                while(!q.empty()){
                    pair<int, int> top = q.front();
                    int x = top.first;
                    int y = top.second;
                    visited[x][y] = true;
                    q.pop();
                    if(x<grid.size()-1 && grid[x+1][y]=='1' && !visited[x+1][y]){
                        q.push({x+1,y});
                        visited[x+1][y] = true;
                    }
                    if(x>0 && grid[x-1][y]=='1' && !visited[x-1][y]){
                        q.push({x-1,y});
                        visited[x-1][y] =true;
                    }
                    if(y<grid[i].size()-1 && grid[x][y+1]=='1' && !visited[x][y+1]){
                        q.push({x,y+1});
                        visited[x][y+1] = true;
                    }
                    if(y>0 && grid[x][y-1]=='1' && !visited[x][y-1]){
                        q.push({x,y-1});
                        visited[x][y-1] = true;
                    }
                }
            }
        }
    }
    return islands;
}

int main(){
    vector<vector<char>> grid = {{'1','1','1'},{'0','1','0'},{'1','1','1'}};
    cout<<numIslands(grid)<<endl;
    return 0;
}
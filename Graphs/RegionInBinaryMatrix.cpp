/*
Given a binary matrix A of size N x M.

 Cells which contain 1 are called filled cell and cell that contain 0 are called empty cell.

Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally.

If one or more filled cells are also connected, they form a region. Find the length of the largest region.

*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool isValid(vector<vector<int>> &A,int i,int j){
    int n = A.size();
    int m = A[0].size();
    if(i<n && i>=0 && j<m && j>=0 && A[i][j]==1)return true;
    return false;
}
int doDFS(vector<vector<int>> &A,int x,int y,vector<vector<bool>> &visited,int &count){
    //The 8 adjacent cells can be accessed using X and Y
    vector<int> X = {0,0,-1,-1,-1,1,1,1};
    vector<int> Y = {1,-1,1,-1,0,-1,1,0};
    visited[x][y]=true;
    A[x][y]=0;
    for(int i=0;i<8;i++){
        int newX = x+X[i];
        int newY = y+Y[i];
        if(isValid(A,newX,newY) && !visited[newX][newY]){
            count++;
            doDFS(A,newX,newY,visited,count);
        }
    }
    return count;
}
int findMaxRegion(vector<vector<int>> &A){
    //Instead of making another array to check a cell is visited or not, lets use A itself.
    //0 for empty
    //1 for filled
    //-1 for visited
    int n = A.size();
    int m = A[0].size();
    //For each unvisited filled cell, we will do a DFS and return the maximum length obtainable
    int maxRange = 0;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int count=1;
            if(!visited[i][j] && A[i][j]==1)
                maxRange = max(maxRange,doDFS(A,i,j,visited,count));
        }
    }
    return maxRange;
}
int main(){
    vector<vector<int>> A = {   {1,1,1},
                                {0,0,1}
                            };
    cout<<findMaxRegion(A)<<endl;
    return 0;
}
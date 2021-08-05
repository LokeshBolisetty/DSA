/*
There is a rectangle with left bottom as  (0, 0) and right up as (x, y). There are N circles such that their centers are inside the rectangle.

Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.

Note :  We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/**
 * Checks if there is a valid path from (0,0) to (x,y) witout touching any circle
 * @param x x co-ordinate of top right of the rectangle
 * @param y y co-ordinate of top right of the rectangle
 * @param N Number of circles
 * @param R Radius of each circle
 * @param A Vector of x co-ordinates of centers of circles
 * @param B Vector of y co-ordinates of centers of circles
 * @return "YES" if there is a valid path, 0 otherwise
 * */
string validPath(int x,int y,int N,int R,vector<int> &A,vector<int> &B){
    //Vector to check if there is a circle in a given cell
    //if grid[i][j]==false then there is no circle in the cell
    //else if grid[i][j]==true then there is a circle in the cell
    vector<vector<bool>> grid(x+1,vector<bool>(y+1,false));

    //Filling the grid with trues wherever a circle is present
    //We assume that number of circles is substantially lesser than the number of cells. 
    //Thats why for each cell, I am checking if there is any circle in there
    //Otherwise we could have checked all the cells each circle is in
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            for(int k = 0;k<N;k++){
                if((A[k]-i)*(A[k]-i)+(B[k]-j)*(B[k]-j)-R*R<=0){
                    if(i==x && j==y)return "NO";
                    grid[i][j]=true;
                }
            }
        }
    }


    //We perform BFS to go to adjacent cells one by one
    //Now for each cell we go, we need to check if any of the adjacent 8 cells are free
    queue<pair<int,int>> q;
    q.push({0,0});
    grid[0][0] = true;
    while(!q.empty()){
        pair<int,int> currentCell = q.front();
        q.pop();
        //grid[currentCell.first][currentCell.second] = true;
        //if(currentCell.first==x && currentCell.second==y)return "YES";
        //cout<<currentCell.first<<"\t"<<currentCell.second<<endl;
        //top
        if(currentCell.second<y && grid[currentCell.first][currentCell.second+1]==false){
            if(currentCell.first==x && currentCell.second+1==y){
                return "YES";
            }
            grid[currentCell.first][currentCell.second+1]=true;
            q.push({currentCell.first,currentCell.second+1});
        }
        //top left 
        if(currentCell.first>0 && currentCell.second<y && grid[currentCell.first-1][currentCell.second+1]==false){
            if(currentCell.first-1==x && currentCell.second+1==y){
                return "YES";
            }
            grid[currentCell.first-1][currentCell.second+1] = true;
            q.push({currentCell.first-1,currentCell.second+1});
        }
        //top right
        if(currentCell.first<x && currentCell.second<y && grid[currentCell.first+1][currentCell.second+1]==false){
            if(currentCell.first+1==x && currentCell.second+1==y){
                return "YES";

            }
            grid[currentCell.first+1][currentCell.second+1] = true;
            q.push({currentCell.first+1,currentCell.second+1});
        }
        //left 
        if(currentCell.first>0 && grid[currentCell.first-1][currentCell.second]==false){
            if(currentCell.first-1==x,currentCell.second==y){
                return "YES";
            }
            grid[currentCell.first-1][currentCell.second] = true;
            q.push({currentCell.first-1,currentCell.second});
        }
        //right
        if(currentCell.first<x && grid[currentCell.first+1][currentCell.second]==false){
            if(currentCell.first+1==x && currentCell.second==y){
                return "YES";
            }
            grid[currentCell.first+1][currentCell.second] = true;
            q.push({currentCell.first+1,currentCell.second});
        }
        //bottom
        if(currentCell.second>0 && grid[currentCell.first][currentCell.second-1]==false){
            if(currentCell.first==x && currentCell.second-1==y){
                return "YES";
            }
            grid[currentCell.first][currentCell.second-1] = true;
            q.push({currentCell.first,currentCell.second-1});
        }
        //bottom left
        if(currentCell.first>0 && currentCell.second>0 && grid[currentCell.first-1][currentCell.second-1]==false){
            if(currentCell.first-1==x && currentCell.second-1==y){
                return "YES";
            }
            grid[currentCell.first-1][currentCell.second-1] = true;
            q.push({currentCell.first-1,currentCell.second-1});
        }
        //bottom right
        if(currentCell.first<x && currentCell.second>0 && grid[currentCell.first+1][currentCell.second-1]==false){
            if(currentCell.first+1==x && currentCell.second-1==y){
                return "YES";
            }
            grid[currentCell.first+1][currentCell.second-1] = true;
            q.push({currentCell.first+1,currentCell.second-1});
        }
    }
    return "NO";
}
int main(){
    int x = 70,y=15;
    int N = 7,R = 7;
    vector<int> A = { 44, 38, 64, 68, 1, 46, 29};
    vector<int> B = {15, 9, 10, 1, 11, 13, 8 };
    cout<<validPath(x,y,N,R,A,B)<<endl;
    return 0;
}
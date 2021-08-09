/*
Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.
Knight's movements on a chess board

The above figure details the movements for a knight ( 8 possibilities ).

If yes, then what would be the minimum number of steps for the knight to move to the said point.

If knight can not move from the source point to the destination point, then return -1.

Note: A knight cannot go out of the board.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/**
 * Checks if the given point is a valid point on the grid
 * @param X X coordinate of the point to check
 * @param Y Y coordinate of the point to check
 * @param M Number of rows in the chess board
 * @param N Number of columns in the chess board
 * @return True if its a valid point, flase otherwise
 * */
bool isValid(int X,int Y,int M,int N){
    if(X<M && Y<N && X>=0 && Y>=0)return true;
    return false;
}

/**
 * Finds the number of steps it takes to reach from (C,D) to (E,F)
 * @param A Number of rows in the chess board
 * @param B Number of columns in the chess board
 * @param C X coordinate of the starting point of the knight in 1 based indexing
 * @param D Y coordinate of the starting point of the knight in 1 based indexing
 * @param E X coordinate of the ending point of the knight in 1 based indexing
 * @param F Y coordinate of the ending point of the knight in 1 based indexing
 * @return Number of steps to reach from starting to ending point, -1 if it's not possible to reach the ending point
 * */
int findPath(int A,int B,int C,int D,int E,int F){
    //Converting 1 based indexes to 0 based indexes
    C--;D--;E--;F--;
    //Vector to store the number of steps required to go upto any point given
    vector<vector<int>> grid(A,vector<int>(B,0));
    queue<pair<int,int>> q;
    q.push({C,D});

    //Vectors for the knight to reach all the 8 locations possible to travel
    vector<int> addX = {2,2,-2,-2,1,1,-1,-1};
    vector<int> addY = {1,-1,1,-1,2,-2,2,-2};
    
    while(!q.empty()){
        int X = q.front().first;
        int Y = q.front().second;
        q.pop();
        if(X==E && Y==F)return grid[X][Y];
        for(int i=0;i<8;i++){
            int newX = X+addX[i];
            int newY = Y+addY[i];
            if(isValid(newX,newY,A,B) && grid[newX][newY]==0){
                grid[newX][newY] = grid[X][Y]+1;
                if(newX==E && newY ==F)return grid[newX][newY];
                q.push({newX,newY});
            }
        }
    }
    return -1;
}

int main(){

    return 0;
}
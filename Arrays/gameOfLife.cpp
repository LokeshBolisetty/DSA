#include<iostream>
#include<vector>
using namespace std;

int countNeighbours(vector<vector<int>> &board, int i, int j){
    int m = board.size();
    int n = board[0].size();
    int count = 0;
    if(i+1<m && board[i+1][j])count++;
    if(i-1>=0 && board[i-1][j])count++;
    if(j+1<n && board[i][j+1])count++;
    if(j-1>=0 && board[i][j-1])count++;
    if(i+1<m && j+1<n && board[i+1][j+1])count++;
    if(i+1<m && j-1>=0 && board[i+1][j-1])count++;
    if(i-1>=0 && j+1<n && board[i-1][j+1])count++;
    if(i-1>=0 && j-1>=0 && board[i-1][j-1])count++;
    return count;
}
void gameOfLife(vector<vector<int>>& board) {  
    int m = board.size(), n = board[0].size();
    vector<vector<int>> answer(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int neighbours = countNeighbours(board, i, j);
            if(neighbours==3)answer[i][j] = 1;
            else if(neighbours<2)answer[i][j] = 0;
            else if(neighbours==2 && board[i][j])answer[i][j]= 1;
            else if(neighbours>3)answer[i][j] = 0;
        }
    }
    board = answer;
}


int main(){
    vector<vector<int>> board = {{0,1,0},
                                 {0,0,1},
                                 {1,1,1},
                                 {0,0,0}};
    gameOfLife(board);
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            cout<<board[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
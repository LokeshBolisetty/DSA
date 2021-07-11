#include<iostream>
#include<vector>
using namespace std;
const int N = 9;
bool isValid(vector<vector<char> > &A, int row, int col,char ele)
{
    int boxStart = row-row%3,colStart = col-col%3;
    for(int i=0;i<9;i++){
        if(A[row][i]==ele)return false;
        if(A[i][col]==ele)return false;
    }
    for(int i=boxStart;i<boxStart+3;i++){
        for(int j=colStart;j<colStart+3;j++){
            if(ele==A[i][j])return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>> &A,int r,int c){
    if(r==9)return true;
    if(c==9){
        return solve(A,r+1,0);
    }
    if(A[r][c]!='.')return solve(A,r,c+1);
    for(char ch='1';ch<='9';ch++){
        if(isValid(A,r,c,ch)){
            A[r][c]=ch;
            if(solve(A,r,c+1))return true;
            A[r][c]='.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>> &A){
    solve(A,0,0);
}
int main(){
    vector<vector<char>> A = {{'5','3','.','.','7','.','.','.','.'},
                              {'6','.','.','1','9','5','.','.','.'}, 
                              {'.','9','8','.','.','.','.','6','.'}, 
                              {'8','.','.','.','6','.','.','.','3'}, 
                              {'4','.','.','8','.','3','.','.','1'}, 
                              {'7','.','.','.','2','.','.','.','6'}, 
                              {'.','6','.','.','.','.','2','8','.'}, 
                              {'.','.','.','4','1','9','.','.','5'}, 
                              {'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(A);
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            cout<<A[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
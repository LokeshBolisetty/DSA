#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isValid(vector<string> &A, int row,int col){
    for(int i=0;i<A.size();i++){
        if(A[row][i]=='Q')return false;
        if(A[i][col]=='Q')return false;
    }
    int i = row,j=col,n = A.size();
    while(i>=0 && i<n && j>=0 && j<n){
        if(A[i][j]=='Q')return false;
        i++;j++; //Botton right
    }
    i = row,j=col,n = A.size();
    while(i>=0 && i<n && j>=0 && j<n){
        if(A[i][j]=='Q')return false;
        i++;j--; //Botton left
    }
    i = row,j=col,n = A.size();
    while(i>=0 && i<n && j>=0 && j<n){
        if(A[i][j]=='Q')return false;
        i--;j--; //Top left
    }
    i = row,j=col,n = A.size();
    while(i>=0 && i<n && j>=0 && j<n){
        if(A[i][j]=='Q')return false;
        i--;j++; //Top right
    }
    return true;
}


bool putNQueens(vector<vector<string>> &ans,vector<string> &A,int row,int col){
    int n = A.size();
    if(row==n)return true;
    if(col==n){
        return putNQueens(ans,A,row+1,0);
    }
    for(int i=col;i<n;i++){
        if(isValid(A,row,i)){
            A[row][i]='Q';
            if(putNQueens(ans,A,row+1,0)){
                ans.push_back(A);
            }
            A[row][i]='.';
        }
    }
    return false;
}

vector<vector<string>> solve(int n){
    vector<vector<string>> ans;
    if(n==2||n==3)return ans;
    string s;
    for(int i=0;i<n;i++)s+=".";
    vector<string> grid;
    for(int i=0;i<n;i++)grid.push_back(s);
    putNQueens(ans,grid,0,0);
    return ans;
}

int main(){
    int n = 10;
    vector<vector<string>> s = solve(n);
    for(int k=0;k<s.size();k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<s[k][i][j]<<" ";
            }cout<<endl;
        }cout<<endl<<endl;
    }
    return 0;
}
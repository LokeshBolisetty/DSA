#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
bool isValid(vector<string> grid){
    int sum = 0;
    unordered_map<char,bool> m;
    for(int j=0;j<9;j++){
        for(int i=0;i<9;i++){
            if(grid[i][j]=='.')continue;
            if(m.find(grid[i][j])!=m.end())return false;
            m[grid[i][j]] = true;
        }
        m.clear();
    }
    m.clear();
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(grid[i][j]=='.')continue;
            if(m.find(grid[i][j])!=m.end())return false;
            m[grid[i][j]] = true;
        }
        m.clear();
    }
    m.clear();
    for(int row = 0;row<9;row=row+3){
        for(int col = 0;col<9;col = col+3){
            for(int i=row+0;i<row+3;i++){
                for(int j=col+0;j<col+3;j++){
                    if(grid[i][j]=='.')continue;
                    if(m.find(grid[i][j])!=m.end())return false;
                    m[grid[i][j]] = true;
                }
            }
            m.clear();
        }
    }       
    return true;
}

int main(){
    vector<string> grid =  {"..4...63.", 
                            ".........", 
                            "5......9.", 
                            "...56....", 
                            "4.3.....1", 
                            "...7.....", 
                            "...5.....", 
                            ".........", 
                            "........."};
    cout<<isValid(grid)<<endl;
    return 0;
}
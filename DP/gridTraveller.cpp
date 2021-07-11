#include<iostream>
#include<vector>
using namespace std;
#define int long long 
int gridTraveler(int m,int n){
    vector<vector<int>> grid(m+1,vector<int>(n+1));
    grid[1][1] = 1;
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(j+1<=n)grid[i][j+1]+=grid[i][j];
            if(i+1<=m)grid[i+1][j]+=grid[i][j];
        }
    }
    return grid[m][n];
}
signed main(){
    cout<<gridTraveler(1,1)<<endl;
    cout<<gridTraveler(2,3)<<endl;
    cout<<gridTraveler(3,2)<<endl;
    cout<<gridTraveler(3,3)<<endl;
    cout<<gridTraveler(18,18)<<endl;
    return 0;
}
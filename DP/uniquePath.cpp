#include<iostream>
#include<vector>
using namespace std;


int uniquePaths(int m, int n) {
    if(m==0 && n==0) return 0;
    vector<vector<int>> dp(m,vector<int>(n));
    for(int i=0;i<m;i++)dp[i][0] = 1;
    for(int j=0;j<n;j++)dp[0][j] = 1;
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            int top = 0;
            if(i-1>=0)top = dp[i-1][j];
            int left = 0;
            if(j-1>=0)left = dp[i][j-1];
            dp[i][j] = top + left;
        }
    }
    return dp[m-1][n-1];
}


int main(){
    int m = 3,n=7;
    cout << uniquePaths(m, n) << endl;
    return 0;
}
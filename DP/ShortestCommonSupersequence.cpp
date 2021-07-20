#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int LongestCommonSubsequence(string &A,string &B){
    int m = A.size();
    int n = B.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0)dp[i][j]=0;
            else if(A[i-1]==B[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int shortestCommonSupersequence(string A,string B){
    int m = A.size();
    int n = B.size();
    return m+n-LongestCommonSubsequence(A,B);
}

int main(){
    string A = "geek";
    string B = "eke";
    cout<<shortestCommonSupersequence(A,B)<<endl;
    return 0;
}
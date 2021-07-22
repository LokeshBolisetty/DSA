#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int LongestCommonSubsequence(string A,string B){
    /*
        We can traverse these strings from the end
        if the last characters of A[0,m-1] and B[0,n-1], match
        LCS(A[0,m-1,B[0,n-1]]) = 1+LCS(A[0,m-2],B[0,n-2])
        else 
        LCS(A[0,m-1,B[0,n-1]]) = max(LCS(A[0,m-2],B[0,n-1])),LCS(A[0,m-1],B[0,n-2]))
        if(m==0 || n==0)return 0
    */
    int m = A.size();
    int n = B.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0)dp[i][j]=0;
            else if(A[i-1]==B[j-1] && i!=j)dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[m][n]>1;
}

int main(){
    string A = "ABCD";
    cout<<LongestCommonSubsequence(A,A)<<endl;
    return 0;
}
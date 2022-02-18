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
    vector<vector<int>> dp(m+1,vector<int> (n+1));
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0)dp[i][j] = 0;
            else if(A[i-1]==B[j-1])dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int LengthOfLongestCommonSubsequence(string text1,string text2){
    //Same logic but faster due to 
    //1. Use of array instead of vector
    //2. Initialising the first row and column to 0 before itself. 
    int s1 = text1.size(),s2 = text2.size();
    int dp[s2+1][s1+1];
    for(int i = 0;i<s1+1;i++)
    {
        for(int j = 0;j<s2+1;j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1;i<=s2;i++){
        for(int j = 1;j<=s1;j++){
            if(text2[i-1]==text1[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[s2][s1];
}

int main(){
    string A = "AGGTAB";
    string B = "GXTXAYB";
    cout<<LongestCommonSubsequence(A,B)<<endl;
    return 0;
}
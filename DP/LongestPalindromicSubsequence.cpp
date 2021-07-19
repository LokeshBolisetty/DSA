/*
Given a string A, find the common palindromic sequence ( A sequence which does not need to be contiguous and is a pallindrome), which is common in itself.

You need to return the length of longest palindromic subsequence in A.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
 * Counts the length of the longest Palindromic Subsequence
 * @param A string whose longest palindrome has to be found out
 * */
int LongestPalindromicSubsequence(string &A){
    int n = A.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }
    // Let l(st,end) is the length of longest palindromic susequence from st to end indices, 
    // if st==end l(st,end) = 1 (single char is always palindromic)
    // if A[st]!=A[end] l(st,end) = max(l(st+1,end),l(st,end-1))
    // if they are equal and j==i+1(there are only two characters) l(i,j) = 2
    // else if they are equal and more than 2 characters A[st]==A[end] l(st,end) = l(st+1,end-1)+2
    /*
    Don't do this. this will cause errors because all required blocks are not filled
    like if you want dp[3][2] for dp[2][4] then dp[2][4] might not be present already. 
    So instead of this first calculate answers for all subsequences of length 2 and then 3 and so on
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(A[i]!=A[j]){
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }else{
                if(j-i==1)dp[i][j]=2;
                else dp[i][j] = dp[i+1][j-1]+2;
            }
        }
    }
    */
    int j;
    for(int l=2;l<=n;l++){
        //l is the length
        for(int i=0;i<n-l+1;i++){
            j=i+l-1;
            if(A[i]==A[j] && l==2)dp[i][j]=2;
            else if(A[i]==A[j]) dp[i][j]=dp[i+1][j-1]+2;
            else dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
        }
    }
    return dp[0][n-1];
}

int main(){
    string A = "bebeeed";
    cout<<LongestPalindromicSubsequence(A)<<endl;
    return 0;
}
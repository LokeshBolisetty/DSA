/*
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.  
    Insert
    Remove
    Replace
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int editDistance(string A,string B){
    int m = A.size();
    int n = B.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0)dp[i][j]=j; //If the first string is emtpy, we need to insert all the char in string 2.So j
            else if(j==0)dp[i][j]=i; //If the second string is empty, we need to insert all the char in string 1. So i
            else if(A[i-1]==B[j-1])dp[i][j]=dp[i-1][j-1]; //If the chars are same, nothing needs to be done
            else{
                dp[i][j]=1+min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]); //CHeck for all possibilities + 1(One operation to change it)
                //dp[i-1][j-1] for replace
                //dp[i-1][j] for removing char from string1
                //dp[i][j-1] for inserting character into string1
                //Whichever is minimum will be considered
            }
        }
    }
    return dp[m][n];
}

int main(){
    string s1 = "sunday", s2 = "saturday";
    cout<<editDistance(s1,s2)<<endl;
    return 0;
}
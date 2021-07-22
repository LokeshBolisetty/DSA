#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DistinctSubsequences(string A, string B)
{
    /*
        If S is the source and T is the text we want to find in S
            Given the string T is an empty string, returning 1 as an empty string can be the subsequence of all.
    Given the string S is an empty string, returning 0 as no string can be the subsequence of an empty string.
    If the last character of S and T do not match, then remove the last character of S and call the recursive function again. 
        Because the last character of S cannot be a part of the subsequence or remove it and check for other characters.
    If the last character of S match then there can be two possibilities, first there can be a subsequence where the last character of S is a part of it and second where it is not a part of the subsequence. So the required value will be the sum of both. 
        Call the recursive function once with last character of both the strings removed and again with only last character of S removed.
    */
    int n = A.length();
    int m = B.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (B[i - 1] == A[j - 1]) //For Rabbit and Rabbbit
            // at i=4 and j=4 since B[3]=B[3] the number of ways of making Rab with Rabb is equal to
            // number of ways of making Rab with Rab + no. of ways of making Ra with Rab
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string B = "lokesh";
    string A = "loookesh";
    cout << DistinctSubsequences(A, B) << endl;
    return 0;
}
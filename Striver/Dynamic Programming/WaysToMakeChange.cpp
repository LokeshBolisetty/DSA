#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //dp[i][j] denotes the number of ways to make change of value j using the first i coins
    vector<vector<long>> dp(n+1, vector<long>(value+1, 0));
    sort(denominations, denominations+n);
    for(int i=1;i<n+1;i++){
        if(denominations[i-1]<=value)dp[i][denominations[i-1]] = 1;
    }
    //dp[1][denominations[0]] = 1;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<value+1;j++){
            long a = dp[i-1][j], b = 0;
            if(j>=denominations[i-1]) b = dp[i][j-denominations[i-1]];
            dp[i][j] += a+b;
        }
    }
    return dp[n][value];
}

int main(){
    int coins[] = {1, 2, 3};
    int value = 4; //Supposed to return 4
    long answer = countWaysToMakeChange(coins, sizeof(coins)/sizeof(int), value);
    cout<<answer<<endl;
    return 0;
}
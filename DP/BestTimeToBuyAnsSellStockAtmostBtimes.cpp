#include<iostream>
#include<vector>
#define INT_MIN -2123131
using namespace std;

int findMaxProfit(vector<int> &stocks,int B){
    //dp[B][i] = max(dp[B][i-1],max(stocks[i]-stocks[j]+profit[t-1][j]) for all j in 0 to i-1)

    int n = stocks.size();
    B = min(B,n/2); //In some test cases, value of B is very large. 
    // Maintaining dp array of that size gives error. Anyways, we wont need more than n/2 transactions
    // (Each transaction is a combination of a buy and sell. So at max n/2 transactions will be needed)
    vector<vector<int>> dp(B+1,vector<int>(n+1,0));
    for(int i=0;i<=n;i++)dp[0][i] = 0;
    for(int i=0;i<=B;i++)dp[i][0] = 0;
    for(int i=1;i<=B;i++){
        for(int j=1;j<n;j++){
            int val = INT_MIN;
            for(int m = 0;m<j;m++){
                val = max(val,stocks[j]-stocks[m]+dp[i-1][m]);
            }
            dp[i][j] = max(val,dp[i][j-1]);
        }
    }
    return dp[B][n-1];
}

int main(){
    vector<int> stocks = { 19230, 13765, 6863, 3840, 8367, 15603, 16327, 15140, 5582, 12937, 9472, 14190, 9541, 4126, 2757, 400, 19685, 15908, 4929, 18136, 16050, 6622, 13439, 265, 5846, 3188, 8756, 4960, 18781, 11139, 5152, 12314 };
    int B = 100000089;
    cout<<findMaxProfit(stocks,B)<<endl;
    return 0;
}
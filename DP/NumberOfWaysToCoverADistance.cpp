/*Given a distance ‘dist, count total number of ways to cover the distance with 1, 2 and 3 steps. 
Input: n = 3
Output: 4
Explanation:
Below are the four ways
 1 step + 1 step + 1 step
 1 step + 2 step
 2 step + 1 step
 3 step
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * Counts the number of ways you can reach the end of a 1D array
 * @param A Length of A
 * */
int countWays(int A){
    vector<int> dp(A);
    dp[0] = 1;
    if(A>1) dp[1] = 2;
    if(A>2) dp[2] = 4; // 1+1+1+1,1+2,2+1,3
    if(A>3)
    for(int i=3;i<A;i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[A-1];
}

int main(){
    int A = 2;
    cout<<countWays(A)<<endl;
    return 0;
}
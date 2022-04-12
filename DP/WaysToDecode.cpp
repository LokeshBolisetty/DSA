/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26

Given an encoded message A containing digits, determine the total number of ways to decode it modulo 109 + 7.
*/
#include<iostream>
#include<vector>
using namespace std;
int WaysToDecode(string A){

    //According to the test cases numbers like "0124213112312" should give 0 as answer
    if(A[0]=='0')return 0;

    #define MOD 1000000007

    //n denotes the size of given string
    int n = A.size();

    //dp[i] stores the number of ways of decoding the first i characters
    vector<long long> dp(n+1);

    //Number of ways of decoding 0 characters is 1
    dp[0] = 1;
    //Any single character can be decoded only in one way
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = 0;

        //The number of ways of decoding i-1 characters can be applied to the ith character also
        //only if the digit is not 0. 0 can only have value if it is preceeded by 1 or 2 
        if(A[i-1]>'0')
            dp[i]=dp[i-1];

        //If there is a possibility for using two digits together, add those ways also
        if(A[i-2]=='1'||
            (A[i-2]=='2'&&A[i-1]<'7'))  
                dp[i]+=dp[i-2];
        
        dp[i] %= MOD;
    }
    return dp[n];
}
int main(){
    string A = "2611055971756562";
    cout<<WaysToDecode(A)<<endl;
    return 0;
}
/*
    Given a N * 2 array A where (A[i][0], A[i][1]) represents the ith pair.

    In every pair, the first number is always smaller than the second number.

    A pair (c, d) can follow another pair (a, b) if b < c , similarly in this way a chain of pairs can be formed.

    Find the length of the longest chain subsequence which can be formed from a given set of pairs.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int chainOfPairs(vector<vector<int>> &A){
    int n = A.size();

    //ans will store the length of the chain of pairs viz answer
    int ans = 1;

    //dp will be initiated to have {A[i][1],1}
    vector<vector<int>> dp(A.begin(),A.end());
    for(int i=0;i<n;i++){
        dp[i][0] = dp[i][1];
        dp[i][1] = 1;
    }

    //Calculating the length of chain of pairs for input upto index i
    for(int i=1;i<n;i++){

        /*Basic idea is to check all the previous elements and find the max length
          for j in [0,i-1]:
            dp[i] = max(dp[j])+1
        */
        vector<int> p = dp[i];
        for(int j=0;j<i;j++){

            //if A[i][0]<dp[j][0] it can not be considered for chaining(given in the question)
            if(A[i][0]>dp[j][0]){
                //If p[1]<dp[j][1]+1 then the length that will be formed now is greater than current length. So go ahead
                /*If the resultant length is same as current length, change it only if the max element of the chain is decreasing due to the change. 
                    If the max element decreases there is a higher possibility of increase in length in the future.  
                */  
                if(p[1]<dp[j][1]+1 || (p[1]==dp[j][1] && p[0]<dp[j][0])){
                    p[1] = dp[j][1]+1;
                    p[0]=A[i][1];
                }
            }
        }
        //Assign the answer to dp[i] (We have been using temporary variable upto now)
        dp[i]=p;
        dp[i][0] = A[i][1];
        if(ans<dp[i][1])ans = dp[i][1]; //Maintain the maximum length in ans
    }
    return ans;
}

int main(){
    vector<vector<int>> A = {
                            {98, 894},
                            {397, 942},
                            {70, 519},
                            {258, 456},
                            {286, 449},
                            {516, 626},
                            {370, 873},
                            {214, 224},
                            {74, 629},
                            {265, 886},
                            {708, 815},
                            {394, 770},
                            {56, 252}};
    cout<<chainOfPairs(A)<<endl;
    return 0;
}
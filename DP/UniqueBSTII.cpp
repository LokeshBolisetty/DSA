/*
Given an integer A, how many structurally unique BST’s (binary search trees) exist that can store values 1…A?
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int countBST(int A){
    // Assuming that we alredy know the solution for 0 to A-1,
    // Number of ways of forming BSTs with A numbers is = ways with 1 as root + 2 as root + .... A as root
    // If we take j as the root, there will be j-1 numbers on the left and A-j numbers on the right
    // So ways(A) = ways(j-1)*ways(A-j) for all j

    //To store the answer for subproblems
    vector<int> dp(A+1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=A;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<" "<<i-j<<endl;
            dp[i]+=dp[j-1]*dp[i-j];
        }
    }

    return dp[A];
}

int main(){
    int A = 5;
    cout<<countBST(A)<<endl;
    return 0;
}
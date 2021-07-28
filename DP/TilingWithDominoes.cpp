/*
Given an integer A you have to find the number of ways to fill a 3 x A board with 2 x 1 dominoes.

Return the answer modulo 109 + 7 .

NOTE:

See the sample explanation for better understanding.
*/
#include<iostream>
#include<vector>
using namespace std;

int findWaysOfTiling(int n){
    vector<int> A(n+1),B(n+1);
    A[0]=1,A[1]=0;
    B[0]=0,B[1]=1;
    for(int i=2;i<=n;i++){
        A[i]=A[i-2]+2*B[i-1];
        B[i] = A[i-1]+B[i-2];
    }
    return A[n];
}

int main(){
    int A = 6;
    cout<<findWaysOfTiling(A)<<endl;
    return 0;
}
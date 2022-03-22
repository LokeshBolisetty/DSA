/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> countBits(int n) {
    vector<int> res(n+1,0);
    for(int i = 1 ; i<=n ; i++){
        res[i] = res[i&(i-1)]+1 ;
    }
    return res ;
}

int main(){
    int n = 5;
    vector<int> answer = countBits(n);
    for(auto x:answer){
        cout<<x<<" ";
    }
    return 0;
}
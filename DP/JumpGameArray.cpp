/*
Given an array of non-negative integers, A, you are initially positioned at the 0th index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.
*/
#include<iostream>
#include<vector>
using namespace std;
int possibleToReachTheEnd(vector<int> &A){
    int n = A.size();
    vector<int> dp(n,0);
    int maxIdx = 0;
    for(int i=0;i<n;i++){
        if(i>maxIdx)return 0;
        maxIdx = max(maxIdx,i+A[i]);
        if(maxIdx>=n-1)return 1;
    }
    return 0;
}
int main(){
    //vector<int> A = { 0, 10, 0, 0, 25, 0, 18, 0, 26, 7, 0, 0, 0, 19, 16, 0, 0, 0, 18, 7, 15, 2, 0, 23, 0, 1, 0, 19, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 20, 25, 0, 26, 0, 0, 0, 0, 25, 0, 0, 15, 16, 29, 0, 0, 24, 0, 0, 17, 0, 0, 22, 30, 6, 0, 0, 0, 21, 24, 0, 12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 18, 16, 0, 0, 20, 0, 0, 0, 0, 14, 7, 0, 0, 8, 0, 19, 0, 0, 22, 20, 18, 0, 26, 0, 0, 0, 0, 0, 28, 0, 0, 8, 0, 9, 28, 30, 0, 10, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 4, 0, 0, 13, 29, 0, 9, 0, 3, 6, 22, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0, 17, 0, 0, 0, 0, 29, 0, 0, 27, 0, 0, 0, 0, 29, 22, 0, 8, 0, 0, 2, 0, 13, 8, 0, 2, 0, 0, 0, 0, 1, 13, 3, 0, 0, 18, 0, 5, 23, 0, 0, 3, 24, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 2, 2, 0, 0, 0, 14, 24, 0, 17, 0, 0, 0, 0, 0, 0, 17, 2, 0, 10, 6, 5, 0, 0, 20, 21, 26, 16, 0, 0, 0, 21, 9, 0, 0, 0, 0, 0, 11, 0, 25, 0, 0, 0, 9, 0, 6, 20, 0, 0, 0, 0, 0, 0, 0, 26, 25, 0, 14, 0, 0, 0, 7, 0, 0, 1, 0, 0, 5, 0, 0, 0, 1, 0, 29, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 25, 16, 0, 0, 0, 0, 16, 23, 0, 0, 11, 0, 26, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 17, 0, 0, 0, 0, 0, 22, 0, 0, 23, 0, 0, 0, 0, 0, 0, 13, 0, 8, 0, 0, 5, 0, 17, 0, 14, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 15, 25, 26, 17, 0, 11, 6, 0, 0, 9, 3, 0, 0, 0, 0, 7, 0, 26, 0, 0, 0, 28, 0, 0, 0, 0, 0, 28, 0, 0, 14, 0, 0, 0, 0, 18, 25, 0, 0, 0, 0, 0, 0, 6, 14, 12, 27, 12, 21, 11, 15, 0, 6, 9, 25, 0, 0, 0, 0, 18, 0, 3, 0, 5, 0, 0, 8, 9, 17, 6, 28, 26, 0, 12, 0, 0, 0, 0, 22, 0, 0, 0, 0, 9, 0, 0, 0, 0, 14, 16, 8, 19, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 9, 0, 0, 23, 0, 0, 0, 0, 9, 0, 0, 13, 7, 0, 22, 0, 0, 0, 14, 26, 0, 27, 0, 0, 4, 0, 0, 0, 0, 0, 17, 0, 0, 9, 0, 2, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 10, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 8, 0, 0, 0, 4, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 19, 0, 0, 0, 21, 0, 14, 0, 23, 0, 18, 0, 0, 0, 0, 0, 0, 0, 10, 0, 7, 0, 0, 0, 0, 0, 0, 0, 10, 16, 0, 16, 0, 0, 30, 0, 0, 4, 0, 0, 0, 0, 0, 0, 3, 0, 25, 0, 0, 0, 0, 20, 0, 0, 0, 5, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 27, 18, 7, 0, 4, 0, 30, 18, 26, 17, 0, 0, 0, 8, 16, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 9, 0, 0, 28, 0, 17, 0, 2, 0, 27, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 0, 6, 0, 19, 23, 0, 0, 0, 20, 0, 0, 16, 0, 0, 0, 0, 0, 16, 0, 0, 0, 4, 0, 0, 0, 0, 24, 8, 0, 0, 25, 12, 0, 3, 0, 5, 21, 0, 0, 3, 0, 18, 25, 10, 30, 24, 0, 14, 0, 0, 18, 0, 0, 0, 0, 0, 0, 18, 0, 15, 0, 27, 0, 0, 22, 0, 0, 0, 0, 14, 0, 17, 0, 18, 29, 0, 0, 23, 0, 2, 0, 0, 0, 0, 23, 0, 25, 0, 0, 0, 2, 0, 2, 0, 0, 5, 28, 0, 0, 18, 0, 0, 0, 0, 0, 0, 17, 19, 0, 0, 0, 26, 0, 0, 0, 0, 3, 0, 0, 29, 11, 0, 0, 4, 0, 27, 11, 0, 3, 0, 0, 18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 20, 0, 18, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 30, 0, 0, 1, 0, 0, 0, 0, 27, 0, 0, 0, 1, 0, 10, 0, 0 };
    vector<int> A = {3,2,1,0,4};
    cout<<possibleToReachTheEnd(A)<<endl;
    return 0;
}
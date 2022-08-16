#include<iostream>
#include<vector>
using namespace std;

//Take 10,20,30,40 for example
//First matrix is 10x20, second is 20x30, third is 30x40
//Now when we loop i from 1 through 3, we split it as 
//10 20,30,40 
//10 takes 0 multiplications as its a single array
//Multiplying 10 with (20, 30, 40) takes 10*20*40 multiplications
//which is arr[start-1]*arr[k]*arr[end] because the resultant matrices for the split are
//(start-1 x k) and (k*end)

int matrixMul(vector<int> &arr, vector<vector<int>> &dp, int start, int end){
    if(start==end)return 0;
    if(dp[start][end]!=-1)return dp[start][end];
    dp[start][end] = INT32_MAX;
    for(int i=start;i<end;i++){
        dp[start][end] = min(dp[start][end], matrixMul(arr, dp, start, i)+ (arr[start-1]*arr[i]*arr[end]) +matrixMul(arr,dp, i+1,end));
    }
    return dp[start][end];
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    //Starting from 1 because 0-1 is the first matrix
    return matrixMul(arr, dp, 1, N-1);
}

int main(){
    vector<int> arr = {4,5,3,2};
    cout<<matrixMultiplication(arr, arr.size())<<endl;
    return 0;
}
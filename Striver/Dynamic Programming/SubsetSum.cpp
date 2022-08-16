#include<iostream>
#include<vector>

using namespace std;

//Gives TLE
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<int> s;
    for(int i=0;i<n;i++){
        if(arr[i]==k)return true;
        for(int x:s){
            if(x+arr[i]==k){
                return true;
            }
            s.push_back(x+arr[i]);
        }
        s.push_back(arr[i]);
    }
    return false;
}

bool subsetSumToKDP(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n+1, vector<bool>(k+1,false));
    for(int i=0;i<arr.size();i++){
        if(k==arr[i])return true;
        dp[i+1][arr[i]] = true;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<k+1;j++){
            if(dp[i-1][j])dp[i][j] = dp[i-1][j];
            else if(j>=arr[i-1] && dp[i-1][j-arr[i-1]])dp[i][j] = true;
        }
    }
    return dp[n][k];
}

int main(){
    vector<int> arr = {60,15,13,10,7,29,47,48,90,70};
    cout<<"Is there a subset whose sum is 19?\n"<<subsetSumToKDP(arr.size(), 19, arr)<<endl;
    return 0;
}
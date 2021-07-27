#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int,int> m;
int Knapsack(vector<int> value,vector<int> weight,int w){

    // There are two possibilites at every element.
    // 1.) The element is included
    // 2.) The element is excluded
    // Recursively we need to do the following
    // If the element is excluded, value is the value of n-1 elements at current weight
    // If the element is included, value is the value of n elements at weight - weight of current element

    int n = value.size();
    vector<vector<int>> dp(n+1,vector<int>(w+1));
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0)dp[i][j]=0;
            else if(weight[i-1]<=j){
                //If the weight of current element is less than total permissible, then we can include this element
                //We keep the maximum of values upto i-1 elements at weight upto current weight-weight of current element 
                dp[i][j] = max(value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][w];
}
int main(){
    vector<int> value = {60,100,120};
    vector<int> weight = {10,20,30};
    int w = 50;
    cout<<Knapsack(value,weight,w)<<endl;
    return 0;
}
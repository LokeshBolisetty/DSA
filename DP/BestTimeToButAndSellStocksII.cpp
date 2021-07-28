/*

Say you have an array, A, for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.

You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
#include<iostream>
#include<vector>
using namespace std;
int findBestTimeToBuy(vector<int> &stocks){
    //Premise: One will never buy a stock at higher price and sell it low
    //And if the price at i is < price at i+1, one should buy the stock at i and sell it at i+1
    int n = stocks.size();
    int profit = 0;
    for(int i=0;i<n-1;i++){
        if(stocks[i]<stocks[i+1])profit+=stocks[i+1]-stocks[i];
    }
    return profit;
}
int main(){
    vector<int> stocks = {1,2,3};
    cout<<findBestTimeToBuy(stocks)<<endl;
    return 0;
}
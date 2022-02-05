/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/
#include<iostream>
#include<vector>
using namespace std;

int SomeoneOnLeetCode(vector<int>& prices) {
    int mp=0;
    int p=0;
    int b=0;
    for(int i=0;i<prices.size();++i)
    {
        p=prices[i]-prices[b];
        if(p<0)
        {
            b=i;
        }
        mp=max(mp,p);
    }
    return mp;
}

int maxProfit(vector<int>& prices) {
    int minPrice = INT32_MAX;
    int maxProfit = 0;
    for(int i=0;i<prices.size();i++){
        if(prices[i]<minPrice)minPrice = prices[i];
        else if(prices[i]-minPrice>maxProfit)maxProfit = prices[i]-minPrice;
    }
    return maxProfit;
}

int main(){
    vector<int> stocks = {7,1,5,3,6,4};
    cout<<maxProfit(stocks)<<endl;
    return 0;
}
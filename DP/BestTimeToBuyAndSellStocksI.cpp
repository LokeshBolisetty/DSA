/*
Say you have an array, A, for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Return the maximum possible profit.
*/
#include<iostream>
#include<vector>
#define INT_MAX 1231232131
using namespace std;
int findBestTimeToBuy(vector<int> &stocks){
    // Inorder to find the maximum profit one should buy at the least cost possible
    // and sell at highest cost possible.
    // The thing to note here is that the lower price should occur before and higher price should occur later
    // So store the smallest element upto now and find the profit with respect to it

    //It stores the least element encountered upto now
    int smallestUptoNow = INT_MAX;
    int ans = 0;
    for(int i=0;i<stocks.size();i++){
        if(smallestUptoNow>stocks[i]){
            smallestUptoNow = stocks[i];
        }else{
            //Profit = selling price-buying price
            //Profit = stocks[i] - smallestUptoNow
            if(ans<stocks[i]-smallestUptoNow)ans = stocks[i]-smallestUptoNow;
        }
    }
    return ans;
}
int main(){
    vector<int> stocks = {1,4,5,2,4};
    cout<<findBestTimeToBuy(stocks)<<endl;
    return 0;
}
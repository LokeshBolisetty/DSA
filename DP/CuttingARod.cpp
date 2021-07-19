/*

Given a rod of length n inches and an array of prices 
    that includes prices of all pieces of size smaller than n. 
Determine the maximum value obtainable by cutting up the 
    rod and selling the pieces. 
For example, if the length of the rod is 8 
    and the values of different pieces are given as the following,
    then the maximum obtainable value is 22 
    (by cutting in two pieces of lengths 2 and 6) 

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#define INT_MIN -2147483647
using namespace std;

int cutter(vector<int> &prices,int target,unordered_map<int,int> &m){
    if(m.find(target)!=m.end())return m[target];
    int ans = prices[target-1];
    for(int i=1;i<target;i++){
        int current = prices[i-1];
        if(m.find(i)!=m.end())current = m[i];
        ans = max(ans,current+cutter(prices,target-i,m));
    }
    m.insert({target,ans});
    return ans;
}

int cutRod(vector<int> &prices,int target){
    unordered_map<int,int> m;
    return cutter(prices,target,m);
}


int main(){
    vector<int> prices = {3,5,8,9,10,17,17,20};
    int target = 8;
    cout<<cutRod(prices,target)<<endl;
    return 0;
}
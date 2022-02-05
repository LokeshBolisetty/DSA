/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.
*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int someonOneLeetcode(int n) {
    if(n==1)
        return 1;

    int two =1;
    int three = 1;
    int five =1 ;
    
    int dp[n+1];
    
    dp[1]=1;
    
    for(int i=2;i<=n;i++){
        int val = min(dp[two]*2, min(dp[three]*3, dp[five]*5));
        if(val==dp[two]*2)
            two++;
        
        if(val==dp[three]*3)
            three++;
        
        if(val == dp[five]*5)
            five++;
        
        dp[i]=val;
    }
    
    return dp[n];
}

int findNthUglyNumber(int n) {
    //faster than 12.59%
    set<long long int> q;
    q.insert(1);
    int count = 1;
    long long int top;
    while(n--){
        top = *q.begin();
        q.erase(q.begin());
        q.insert(top*2);
        q.insert(top*3);
        q.insert(top*5);
    }
    return top;
}

int main(){
    int n= 10;
    cout<<someonOneLeetcode(n)<<endl;
    return 0;
}
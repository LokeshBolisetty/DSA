#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int DivideIntegers(int dividend,int divisor){
    if(divisor==0)return INT_MAX;
    if(dividend==divisor)return 1;
    if(dividend<divisor && dividend>0)return 0;
    if(divisor==INT_MIN)return 0;
    if(divisor==1)return dividend;
    if(divisor==-1)return (dividend==INT_MIN)?INT_MAX:-dividend;
    int sign = ((dividend<0)^(divisor<0))?-1:1;
    int a = dividend==INT_MIN? INT_MAX : abs(dividend);
    int b = divisor==INT_MIN? INT_MAX : abs(divisor);
    int answer = 0;
    while(a>=b){
        a-=b;
        answer++;
    }
    return answer;
}
int main(){
    int dividend = -2147483648;
    int divisor=-10000000;
    cout<<DivideIntegers(dividend,divisor)<<endl;
    return 0;
}
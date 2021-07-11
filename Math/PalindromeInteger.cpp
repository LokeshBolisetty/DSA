#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool PalindromeInteger(int A){
    // We need to check if the first and last digit of the number is same or not. 
    // To find the first digit, we need to know the number of digits in that number first. So,
    if(A>0)return false;
    int n=A;
    int divisor=1;
    while((n/divisor)>=10){
        divisor*=10;
    }
    while(A>0){
        int leading = A/divisor;
        int trailing = A%10;
        if(leading!=trailing)return false;
        A = (A%divisor)/10;
        divisor/=100;
    }
    return true;
}
int main(){
    int A;
    cin>>A;
    cout<<PalindromeInteger(A)<<endl;
    return 0;
}
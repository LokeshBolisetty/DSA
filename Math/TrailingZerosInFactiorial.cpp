#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int TrailingZerosInFactorial(int A){
    //We need to find min(twos,fives) in the prime factors of A
    //No of twos is always higher than number of fives
    //So we only need to find out number of fives
    int count=0;
    for(int i=5;A/i>0;i*=5){
        count += A/i;
    }
    return count;
}
int main(){
    int A = 100;
    cout<<TrailingZerosInFactorial(A)<<endl;
    return 0;
}
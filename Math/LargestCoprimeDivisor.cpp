#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int GCD(int a,int b){
    if(b==0)return a;
    return GCD(b,a%b);
}
int LargestCoprimeDivisor(int A,int B){
    while(GCD(A,B)!=1){
        A = A/GCD(A,B);
    }
    return A;
}
int main(){
    int A = 15,B=3;
    cout<<LargestCoprimeDivisor(B,A)<<endl;
    return 0;
}
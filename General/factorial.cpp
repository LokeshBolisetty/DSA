#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int factorial(int n){
    if(n==1 || n==0) return 1;
    else return n*factorial(n-1);
}
int main(){
    int n = 10;
    cout<<factorial(10)<<endl;
    return 0;
}
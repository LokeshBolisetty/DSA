#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool isInteger(float A){
    if(floor(A)==A)return true;
    return false;
}
int isPower(int A) {
    if(A==1)return 1;
    for(int i=2;i<=sqrt(A);i++){
        if(isInteger(log(A)/log(i)))return 1;
    }
    return 0;
}

int main(){
    int A=4;
    cout<<isPower(A)<<endl;
}
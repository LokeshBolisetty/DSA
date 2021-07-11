#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int GridUnique(int A,int B){
    A--;B--;
    if(A==0||B==0)return 1;
    if(A<B)swap(A,B);
    long long int answer=1;
    for(int i=A+1;i<=A+B;i++){
        answer*=i;
        answer/=(i-A);
    }
    return answer;
}
int main(){
    int A = 15,B=9;
    cout<<GridUnique(A,B)<<endl;
    return 0;
}
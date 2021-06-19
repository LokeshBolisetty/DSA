#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int fact(int A){
    if(A<2)return 1;
    return (A*fact(A-1))%1000000007;
}
long long power(long long x,long long y){
    long long res=1; 
    while(y){
        if(y&1) res = (res*x)%1000000007; 
        y>>=1; 
        x = (x*x)%1000000007;
    }
    return res;
}
int CityTour(int A,vector<int> &B){
    int K= B.size();
    sort(B.begin(),B.end());
    long long int denom=1,count=0;
    for(int i=0;i<K-1;i++){
        denom = (denom*fact(B[i+1]-B[i]-1))%1000000007;
        count+=B[i+1]-B[i]-2;
    }
    return (((fact(A-K)/denom)%1000000007)*power(2,count))%1000000007;
}
int main(){
    int N = 5;
    vector<int> B = {1,3};
    cout<<CityTour(N,B)<<endl;
    return 0;
}
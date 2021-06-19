#include<iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> SpiralOrderMatrix(const vector<vector<int>> &A){
       vector<int> v;
    int n = A.size(),m=A[0].size();
    int T = 0,L=0,B=n-1,R=m-1;
    int dir = 0;
    while(T<=B && L<=R){
        if(dir==0){
            for(int i =L;i<=R;i++){
                v.push_back(A[T][i]);
            }
            T++;dir=1;
        }
        else if(dir==1){
            for(int i=T;i<=B;i++){
                v.push_back(A[i][R]);
            }
            R--;dir=2;
        }
        else if(dir==2){
            for(int i =R;i>=L;i--){
                v.push_back(A[B][i]);
            }
            B--; dir=3;
        }else{
            for(int i=B;i>=T;i--){
                v.push_back(A[i][L]);
            }L++;dir=0;
        }
    }
    return v;
}
int main(){
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> spiral = SpiralOrderMatrix(A);
}
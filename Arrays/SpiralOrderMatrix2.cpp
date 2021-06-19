#include<iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> SpiralOrderMatrix(int A){
    vector<vector<int>> v(A,vector<int> (A));
    int n = A,m=A;
    int T = 0,L=0,B=n-1,R=m-1;
    int dir = 0;
    int p=1;
    while(T<=B && L<=R){
        if(dir==0){
            for(int i =L;i<=R;i++){
                v[T][i]=p;
                p++;
            }
            T++;dir=1;
        }
        else if(dir==1){
            for(int i=T;i<=B;i++){
                v[i][R]=p;
                p++;
            }
            R--;dir=2;
        }
        else if(dir==2){
            for(int i =R;i>=L;i--){
                v[B][i]=p;
                p++;
            }
            B--; dir=3;
        }else{
            for(int i=B;i>=T;i--){
                v[i][L]=p;
                p++;
            }L++;dir=0;
        }
    }
    return v;
}
int main(){
    int n = 3;
    vector<vector<int>> A = SpiralOrderMatrix(n);
    for(int i =0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
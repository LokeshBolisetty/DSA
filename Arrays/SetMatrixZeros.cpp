#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void SetMatrixZeros(vector<vector<int>> &A){
    long long int m = A.size();
    long long int n = A[0].size();
    vector<int> z(n,0);
    set<long long int> s;
    for(long long int i =0;i<m;i++){
        bool flag = false;
        for(long long int j=0;j<n;j++){
            if(A[i][j]==0){
                flag=true;
                s.insert(j);
            }
        }
        if(flag){
            A[i]=z;
        }
    }
    for(auto it=s.begin();it!=s.end();it++){
        for(long long int i=0;i<m;i++){
            A[i][*it]=0;
        }
    }
}
int main(){

    vector<vector<int>> A = {{1,0,1},{1,1,1},{1,1,1}};
    SetMatrixZeros(A);
    for(int i =0;i<A.size();i++){
        for(int j=0;j<A.size();j++){
            cout<<A[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
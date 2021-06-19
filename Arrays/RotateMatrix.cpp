#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void RotateMatrix90Clock(vector<vector<int>> &A){
    //First Transpose the matrix
    for(int i =0;i<A.size();i++){
        for(int j=0;j<i+1;j++){
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i]=temp;
        }
    }
    //Now swap the columns
    int n = A.size();
    n=n/2;
    for(int i =0;i<A.size();i++){
        for(int j=0;j<n;j++){
            int temp = A[i][j];
            A[i][j] = A[i][A.size()-j-1];
            A[i][A.size()-j-1] = temp;
        }
    }
}
void TransposeMatrix(vector<vector<int>> &A){
    for(int i =0;i<A.size();i++){
        for(int j=0;j<i+1;j++){
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i]=temp;
        }
    }
}
int main(){
    vector<vector<int>> A= {{1,2,3},{4,5,6},{7,8,9}};
    /*TransposeMatrix(A);
    for(int i =0;i<A.size();i++){
        for(int j=0;j<A.size();j++){
            cout<<A[i][j]<<" ";
        }cout<<endl;
    }
    cout<<endl<<endl<<endl;*/
    RotateMatrix90Clock(A);
    for(int i =0;i<A.size();i++){
        for(int j=0;j<A.size();j++){
            cout<<A[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
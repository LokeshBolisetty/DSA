#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MinStepsInInfiniteGrid(vector<int> A,vector<int> B){
    int n = A.size();
    int steps = 0;
    for(int i =0;i<n-1;i++){
        steps+=max(abs(A[i]-A[i+1]),abs(B[i]-B[i+1]));
    }
    return steps;
}
int main(){
    vector<int> A = {-7,-13};
    vector<int> B = {1,-5};
    cout<<MinStepsInInfiniteGrid(A,B);
}
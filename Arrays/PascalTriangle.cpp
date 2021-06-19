#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
The element on ith line jth position of a pascal's triangle is iCj

nCr = n!/(n-r)!*r!
nC(r-1) = n!/(n-r+1)!*(r-1)!
nCr = nC(r-1)*(n-r+1)/r
*/
vector<vector<int>> PrintPascal(int A){
    vector<vector<int>> answer(A);
    for(int i =1;i<=A;i++){
        int c = 1;
        for(int j=1;j<=i;j++){
            answer[i-1].push_back(c);
            c = c*(i-j)/j;
        }
    }
    return answer;
}
int main(){
    int n  = 10;
    vector<vector<int>> v = PrintPascal(n);
    for(int i =0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MaxSumOfSubMatrices(vector<vector<int>> A,int B){
     int n = A.size(), ans = INT_MIN;
    vector<vector<int>> rc(n, vector<int>(n, 0));
    vector<vector<int>> c(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == 0)
                rc[i][j] = A[i][j];
            else {
                rc[i][j] = A[i][j] + rc[i][j - 1];
                if (j - B >= 0)
                    rc[i][j] -= A[i][j - B];
            }
        }
    }
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            if (i == 0)
                c[i][j] = rc[i][j];
            else {
                c[i][j] = rc[i][j] + c[i - 1][j];
                if (i - B >= 0) {
                    c[i][j] -= rc[i - B][j];
                }
            }
            if (i >= B - 1 && j >= B - 1)
                ans = max(ans, c[i][j]);
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> A = {{1,1,1,1,1},{2,2,2,2,2,},{3,3,3,3,3},{4,4,4,4,4},{5,5,5,5,5}};
    cout<<MaxSumOfSubMatrices(A,3)<<endl;
    return 0;
}
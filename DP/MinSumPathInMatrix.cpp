#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int countMinPath(vector<vector<int>> &A){
    int n = A.size();
    int m = A[0].size();

    // For a row there is only one way to go
    // The sum is just the addition of all the values in that row
    for(int i=1;i<m;i++){
        A[0][i]+=A[0][i-1];
    }

    // For a single column too there is only one way to go
    // The sum is just the addition of all the values in that column
    for(int i=1;i<n;i++){
        A[i][0] += A[i-1][0];
    }

    //A[i][j]'s value will be modified to the countMinPath(i,j)
    //i.e A[i][j] after modification will hold the value corresponding to 
    //moving from (0,0) to (i,j) ensuring the least sum
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            A[i][j] += min(A[i-1][j],A[i][j-1]);
        }
    }
    return A[n-1][m-1];
}

int main(){
    vector<vector<int>> A = {
  {20, 29, 84, 4, 32, 60, 86, 8, 7, 37},
  {77, 69, 85, 83, 81, 78, 22, 45, 43, 63},
  {60, 21, 0, 94, 59, 88, 9, 54, 30, 80},
  {40, 78, 52, 58, 26, 84, 47, 0, 24, 60},
  {40, 17, 69, 5, 38, 5, 75, 59, 35, 26},
  {64, 41, 85, 22, 44, 25, 3, 63, 33, 13},
  {2, 21, 39, 51, 75, 70, 76, 57, 56, 22},
  {31, 45, 47, 100, 65, 10, 94, 96, 81, 14},
};
    cout<<countMinPath(A)<<endl;
    return 0;
}
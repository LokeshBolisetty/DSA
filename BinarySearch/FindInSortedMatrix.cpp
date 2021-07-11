#include<iostream>
#include<vector>
using namespace std;
// Rows and columns sorted
int FindInSortedMatrix(vector<vector<int>> &A,int target){
    int n = A.size(),m = A[0].size(),i=0,j=m-1;
    while(i<n && j>=0){
        if(A[i][j]==target)return 1;
        else if(A[i][j]>target)j--;
        else if(A[i][j]<target)i++; 
    }
    return 0;
}
// In case rows are sorted and the starting element of each row is greater than 
// the last element of previous row. 
int Find(vector<vector<int>> &A,int B){
    int n=A.size(),m=A[0].size(),i=n-1,j=0;
    while(i>=0 && j<m){
        if(A[i][j]==B)return 1;
        if(A[i][j]<B)j++;
        else i--;
    }
    return 0;
}
int main(){
    vector<vector<int>> v = {{3, 3, 11, 12, 14},
                             {16, 17, 30, 34, 35},
                             {45, 48, 49, 50, 52},
                             {56, 59, 63, 63, 65},
                             {67, 71, 72, 73, 79},
                             {80, 84, 85, 85, 88},
                             {88, 91, 92, 93, 94}};
    int a = 94;
    cout<<Find(v,a)<<endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int DFS(vector<vector<int>> &A, int i,int j,int sum,int minUptoNow){
    sum+=A[i][j];
    if(sum<minUptoNow)minUptoNow = sum;

    if(i==A.size()-1 && j==A[0].size()-1){
        return minUptoNow;
    }
    
    
    int a=INT32_MIN,b=INT32_MIN;
    if(i<A.size()-1){
        a = DFS(A,i+1,j,sum,minUptoNow);
    }
    if(j<A[0].size()-1){
        b = DFS(A,i,j+1,sum,minUptoNow);
    }
    return max(a,b);
}
//Write a function to calculate the maxmium of minimum sum upto any point int a 2D array from 0,0 to n,m
int maxSum(vector<vector<int> > &A){
    int a = DFS(A,0,0,0,0);
    if(a>0)return 0;
    else return abs(a);
}
int main(){
    vector<vector<int>> A;
    A =  {{-2,-3,-5},{-5,-2,-1},{10,30,-5}};
    cout<<maxSum(A)<<endl;
    return 0;
}